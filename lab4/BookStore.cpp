#include "BookStore.h"

ostream& operator<<(ostream &outStream, const BookStore &bookStoreToPrint)
{
  outStream << "Inventory: " << endl;
  outStream << bookStoreToPrint.inventory;
  outStream << "Customers: " << endl;
  outStream << bookStoreToPrint.customers;
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
  customers.setItem(insCustomer->getLastName(), insCustomer);
}
bool BookStore::RemoveCustomer(Customer target, Customer &removedCustomer)
{

}

void BookStore::ProcessTransactionData(vector<string> transactionData)
{

}