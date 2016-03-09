#include "BookStore.h"

ostream& operator<<(ostream &outStream, const BookStore &bookStoreToPrint)
{
  bookStoreToPrint.PrintInventory(outStream);
  bookStoreToPrint.PrintCustomers(outStream);
  return outStream;
}

BookStore::BookStore()
{
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
  int copiesLeft;
  copiesLeft = inventory.RemoveOrDecrement(*target, removedBookPointer);
  if (copiesLeft == -1) {
    return false;
  }
  return true;
}

bool BookStore::AddCustomer(Customer* insCustomer)
{
  string hash = insCustomer->getFirstName() + insCustomer->getLastName();
  customers.setItem(hash, insCustomer);
}
bool BookStore::RemoveCustomer(Customer target, Customer &removedCustomer)
{

}

void BookStore::ProcessTransactionData(Transaction trans)
{
}

void BookStore::PrintInventory(ostream& outStream) const
{
  outStream << "Inventory: " << endl;
  // outStream << inventory;
}
void BookStore::PrintCustomers(ostream& outStream) const
{
  outStream << "Customers: " << endl;
  outStream << customers;
}

bool BookStore::PrintCustomerHistory(ostream& outStream, const Customer &myCustomer) const
{
  string hash = myCustomer.getFirstName() + myCustomer.getLastName();
  Customer* cust = customers.getItem(hash);
  cust->PrintHistory(outStream);
}