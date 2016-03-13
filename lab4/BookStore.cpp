#include "BookStore.h"

ostream& operator<<(ostream &outStream, const BookStore &bookStoreToPrint)
{
  bookStoreToPrint.PrintInventory();
  bookStoreToPrint.PrintCustomers();
  return outStream;
}

BookStore::BookStore()
{
}
BookStore::BookStore(ostream* outStream)
{
  this->outStream = outStream;
}
BookStore::BookStore(ostream* outStream, ostream* errStream)
{
  this->outStream = outStream;
  this->errStream = errStream;
}
BookStore::~BookStore()
{
}

float BookStore::getBalance() const
{
  return balance;
}
ostream* BookStore::getOutStream() const
{
  return outStream;
}
ostream* BookStore::getErrStream() const
{
  return errStream;
}

bool BookStore::setBalance(float balance)
{
  this->balance = balance;
  return true;
}
bool BookStore::setOutStream(ostream* outStream)
{
  this->outStream = outStream;
  return true;
}
bool BookStore::setErrStream(ostream* errStream)
{
  this->errStream = errStream;
  return true;
}

Customer* BookStore::getCustomer(const Customer &myCustomer) const
{
  string hash = myCustomer.getFirstName() + myCustomer.getLastName();
  return customers.getItem(hash);
}

bool BookStore::AddBook(Book* insBook, int copies)
{
  inventory.InsertOrIncrement(insBook, copies);
  return true;
}
bool BookStore::RemoveBook(Book* target)
{
  int copiesLeft;
  Book* removedBookPointer;
  copiesLeft = inventory.RemoveOrDecrement(*target, removedBookPointer);
  if (copiesLeft == -1) {
    delete removedBookPointer;
    return false;
  }
  delete removedBookPointer;
  return true;
}

bool BookStore::AddCustomer(Customer* insCustomer)
{
  string hash = insCustomer->getFirstName() + insCustomer->getLastName();
  customers.setItem(hash, insCustomer);
}
bool BookStore::RemoveCustomer(Customer target)
{
  string hash = target.getFirstName() + target.getLastName();
  Customer* delCustomer;
  customers.removeItem(hash, delCustomer);
  delete delCustomer;
}

bool BookStore::ProcessPurchase(Customer myCustomer, Book* myBook)
{
  Customer* purchasingCustomer = getCustomer(myCustomer);
  if (purchasingCustomer == NULL)
  {
    *errStream << "Customer " << myCustomer.getFirstName() << " " << myCustomer.getLastName() << " not found" << endl;
    delete myBook;
    return false;
  }
  Book* purchasedBook;
  int booksLeft = inventory.RemoveOrDecrement(*myBook, purchasedBook);
  if (booksLeft == -1)
  {
    *errStream << "Book " << myBook->getTitle() << " not found" << endl;
    delete myBook;
    return false;
  }
  float bookCost = purchasedBook->getCost();
  bookCost = purchasingCustomer->applyDiscount(bookCost, purchasedBook->getType());
  balance += bookCost;

  // Check for transitioning to Gold Customer status
  float totalSpent = purchasingCustomer->IncrementAndReturnAmtSpent(bookCost);
  if (purchasingCustomer->getStatus() == "normal" && totalSpent > 200)
  {
    purchasingCustomer->setStatus("gold");
  }

  PurchaseTransaction* trans = new PurchaseTransaction("Purchase", bookCost, myBook);
  purchasingCustomer->AddTransactionToHistory(trans);
  return true;
}

bool BookStore::ProcessReturn(Customer myCustomer, Book* myBook, Book* copiedBook)
{
  Customer* purchasingCustomer = getCustomer(myCustomer);
  if (purchasingCustomer == NULL)
  {
    *errStream << "Customer " << myCustomer.getFirstName() << " " << myCustomer.getLastName() << " not found" << endl;
    delete myBook;
    delete copiedBook;
    return false;
  }
  float bookCost = purchasingCustomer->ReturnCostOfPurchasedBook(myBook);
  if (bookCost == -1)
  {
    *errStream << "Customer never bought book " << myBook->getTitle() << endl;
    delete myBook;
    delete copiedBook;
    return false;
  }
  inventory.InsertOrIncrement(myBook, 1);

  // Check for transitioning to Normal Customer status
  float totalSpent = purchasingCustomer->IncrementAndReturnAmtSpent(-1 * bookCost);
  if (purchasingCustomer->getStatus() == "gold" && totalSpent < 200)
  {
    purchasingCustomer->setStatus("normal");
  }

  ReturnTransaction* trans = new ReturnTransaction("Return", bookCost, copiedBook);
  purchasingCustomer->AddTransactionToHistory(trans);
  return true;
}

bool BookStore::ProcessTradeIn(Customer myCustomer, Book* myBook, Book* copiedBook)
{
  Customer* purchasingCustomer = getCustomer(myCustomer);
  if (purchasingCustomer == NULL)
  {
    *errStream << "Customer " << myCustomer.getFirstName() << " " << myCustomer.getLastName() << " not found" << endl;
    delete myBook;
    delete copiedBook;
    return false;
  }
  inventory.InsertOrIncrement(myBook, 2);
  Book* getBookCost;
  inventory.RemoveOrDecrement(*copiedBook, getBookCost);
  float bookCost = getBookCost->getCost();
  TradeInTransaction* trans = new TradeInTransaction("Trade In", bookCost, copiedBook);
  purchasingCustomer->AddTransactionToHistory(trans);
  return true;
}

void BookStore::PrintInventory() const
{
  *outStream << "Money in the till: $" << balance << " Inventory: " << endl;
  *outStream << inventory;
}
void BookStore::PrintCustomers() const
{
  *outStream << "Customers: " << endl;
  *outStream << customers;
}

bool BookStore::PrintCustomerHistory(const Customer &myCustomer) const
{
  getCustomer(myCustomer)->PrintHistory(*outStream);
}
