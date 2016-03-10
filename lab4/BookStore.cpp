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

bool BookStore::AddBook(Book* insBook, int copies)
{
  inventory.Insert(insBook, copies);
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
bool BookStore::RemoveCustomer(Customer target, Customer &removedCustomer)
{

}

bool BookStore::ProcessPurchase(Customer myCustomer, Book* myBook)
{
  Customer* purchasingCustomer = getCustomer(myCustomer);
  if (purchasingCustomer == NULL)
  {
    *outStream << "Customer " << myCustomer.getFirstName() << " " << myCustomer.getLastName() << " not found" << endl;
    return false;
  }
  Book* purchasedBook;
  int booksLeft = inventory.RemoveOrDecrement(*myBook, purchasedBook);
  if (booksLeft == -1)
  {
    *outStream << "Book " << myBook->getTitle() << " not found" << endl;
    return false;
  }
  float bookCost = purchasedBook->getCost();
  balance += bookCost;
  purchasingCustomer->incrementAmtSpent(bookCost);
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

Customer* BookStore::getCustomer(const Customer &myCustomer) const
{
  string hash = myCustomer.getFirstName() + myCustomer.getLastName();
  return customers.getItem(hash);
}