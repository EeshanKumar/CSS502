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
BookStore::~BookStore()
{
}

float BookStore::getBalance() const
{
  return balance;
}
bool BookStore::setBalance(float balance)
{
  this->balance = balance;
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
bool BookStore::RemoveBook(Book* target, Book &removedBookPointer)
{
  // int copiesLeft;
  // copiesLeft = inventory.RemoveOrDecrement(*target, removedBookPointer);
  // if (copiesLeft == -1) {
  //   return false;
  // }
  // return true;
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
    *outStream << "Customer " << myCustomer.getFirstName() << " " << myCustomer.getLastName() << " not found" << endl;
    delete myBook;
    return false;
  }
  Book* purchasedBook;
  int booksLeft = inventory.RemoveOrDecrement(*myBook, purchasedBook);
  if (booksLeft == -1)
  {
    *outStream << "Book " << myBook->getTitle() << " not found" << endl;
    delete myBook;
    return false;
  }
  float bookCost = purchasedBook->getCost();
  bookCost = purchasingCustomer->applyDiscount(bookCost);
  balance += bookCost;
  float totalSpent = purchasingCustomer->IncrementAndReturnAmtSpent(bookCost);

  // // Check for transitioning to Gold Customer status
  // if (purchasingCustomer->applyDiscount(100) == 100 && totalSpent > 200)
  // {
  //   purchasingCustomer->setStatus("gold");
  // }

  PurchaseTransaction* trans = new PurchaseTransaction("Purchase", bookCost, myBook);
  purchasingCustomer->AddTransactionToHistory(trans);
  return true;
}

bool BookStore::ProcessReturn(Customer myCustomer, Book* myBook, Book* copiedBook)
{
  Customer* purchasingCustomer = getCustomer(myCustomer);
  if (purchasingCustomer == NULL)
  {
    *outStream << "Customer " << myCustomer.getFirstName() << " " << myCustomer.getLastName() << " not found" << endl;
    delete myBook;
    return false;
  }
  float bookCost = purchasingCustomer->ReturnCostOfPurchasedBook(myBook);
  if (bookCost == -1)
  {
    *outStream << "Customer never bought book " << myBook->getTitle() << endl;
    delete myBook;
    return false;
  }
  inventory.InsertOrIncrement(myBook, 1);
  float totalSpent = purchasingCustomer->IncrementAndReturnAmtSpent(bookCost);
  ReturnTransaction* trans = new ReturnTransaction("Return", bookCost, copiedBook);
  purchasingCustomer->AddTransactionToHistory(trans);
  return true;
}

bool BookStore::ProcessTradeIn(Customer myCustomer, Book* myBook, Book* copiedBook)
{
  Customer* purchasingCustomer = getCustomer(myCustomer);
  if (purchasingCustomer == NULL)
  {
    *outStream << "Customer " << myCustomer.getFirstName() << " " << myCustomer.getLastName() << " not found" << endl;
    delete myBook;
    return false;
  }
  inventory.InsertOrIncrement(myBook, 1);
  float bookCost = copiedBook->getCost();
  float totalSpent = purchasingCustomer->IncrementAndReturnAmtSpent(-1 * bookCost);
  TradeInTransaction* trans = new TradeInTransaction("Trade In", bookCost, copiedBook);
  purchasingCustomer->AddTransactionToHistory(trans);
  return true;
}

void BookStore::PrintInventory() const
{
  *outStream << "Inventory: " << endl;
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
