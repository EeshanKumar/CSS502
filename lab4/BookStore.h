#include <iostream>
using namespace std;
#include "Book.h"
#include "GraphicNovel.h"
#include "AudioBook.h"
#include "BST.h"
#include "Customer.h"
#include "Hash.h"

#ifndef BOOKSTORE_H
#define BOOKSTORE_H

class BookStore
{
friend ostream& operator<<(ostream &outStream, const BookStore &bookStoreToPrint);

public:
  BookStore();
  ~BookStore();
  bool AddBook(Book* insBook, int copies);
  bool RemoveBook(Book* target, Book &removedBookPointer);

  bool AddCustomer(Customer* insCustomer);
  bool RemoveCustomer(Customer target, Customer &removedCustomer);

  void ProcessTransactionData(Transaction trans);

  void PrintInventory(ostream& outStream) const;
  void PrintCustomers(ostream& outStream) const;
  bool PrintCustomerHistory(ostream& outStream, const Customer &myCustomer) const;

private:
  BST<Book> inventory;
  Hash<Customer> customers;
};

#endif //BOOKSTORE_H