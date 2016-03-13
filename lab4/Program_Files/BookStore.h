#include <iostream>
using namespace std;
#include "Book.h"
#include "GraphicNovel.h"
#include "AudioBook.h"
#include "BST.h"
#include "Customer.h"
#include "SeniorCustomer.h"
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
  BookStore(ostream* outStream, ostream* errStream);
  ~BookStore();

  float getBalance() const;
  ostream* getOutStream() const;
  ostream* getErrStream() const;

  bool setBalance(float balance);
  bool setOutStream(ostream* outStream);
  bool setErrStream(ostream* errStream);

  Customer* getCustomer(const Customer &myCustomer) const;

  bool AddBook(Book* insBook, int copies);
  bool RemoveBook(Book* target);

  bool AddCustomer(Customer* insCustomer);
  bool RemoveCustomer(Customer target);

  bool ProcessPurchase(Customer myCustomer, Book* myBook);
  bool ProcessReturn(Customer myCustomer, Book* myBook, Book* copiedBook);
  bool ProcessTradeIn(Customer myCustomer, Book* myBook, Book* copiedBook);

  void PrintInventory() const;
  void PrintCustomers() const;
  bool PrintCustomerHistory(const Customer &myCustomer) const;

private:
  BST<Book> inventory;
  Hash<Customer> customers;
  float balance = 0;
  ostream* outStream;
  ostream* errStream;
};

#endif //BOOKSTORE_H