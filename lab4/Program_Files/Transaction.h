#include <iostream>
using namespace std;
#include "Book.h"

#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction
{
  friend ostream& operator<<(ostream &outStream, Transaction* transToPrint);

public:
  Transaction();
  Transaction(string transType);
  Transaction(string transType, float transAmt);
  Transaction(string transType, float transAmt, Book* refBook);
  ~Transaction();

  string getTransType() const;
  float getTransAmount() const;
  Book* getBook() const;
  bool getReturned() const;

  bool setTransType(string transType);
  bool setTransAmt(float transAmt);
  bool setBook(Book* refBook);
  bool setReturned(bool returned);

  virtual void Print(ostream &outStream) const = 0;

protected:
  string transType;
  float transAmt;
  Book* refBook;
  bool returned = false;
};

#endif //TRANSACTION_H