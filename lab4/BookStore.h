#include <iostream>
using namespace std;
#include "Book.h"
#include "GraphicNovel.h"
#include "AudioBook.h"
#include "BST.h"
#include "Customer.h"
#include "Hash.h"
#include "Transaction.h"
#include "PurchaseTransaction.h"
#include "ReturnTransaction.h"
#include "TradeInTransaction.h"

#ifndef BOOKSTORE_H
#define BOOKSTORE_H

class BookStore
{
friend ostream& operator<<(ostream &outStream, const BookStore &bookStoreToPrint);

public:
  BookStore();
  BookStore(ostream* outStream);
  ~BookStore();

  float getBalance() const;
  bool setBalance(float balance);
  Customer* getCustomer(const Customer &myCustomer) const;

  bool AddBook(Book* insBook, int copies);
  bool RemoveBook(Book* target, Book &removedBookPointer);

  bool AddCustomer(Customer* insCustomer);
  bool RemoveCustomer(Customer target, Customer &removedCustomer);

  bool ProcessPurchase(Customer myCustomer, Book* myBook);

  void PrintInventory() const;
  void PrintCustomers() const;
  bool PrintCustomerHistory(const Customer &myCustomer) const;

private:
  BST<Book> inventory;
  Hash<Customer> customers;
  float balance = 0;
  ostream* outStream;
};

#endif //BOOKSTORE_H