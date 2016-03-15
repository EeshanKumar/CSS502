#include "Transaction.h"

Transaction::Transaction()
{
}
Transaction::Transaction(string transType)
{
  this->transType = transType;
}
Transaction::Transaction(string transType, float transAmt)
{
  this->transType = transType;
  this->transAmt = transAmt;
}
Transaction::Transaction(string transType, float transAmt, Book* refBook)
{
  this->transType = transType;
  this->transAmt = transAmt;
  this->refBook = refBook;
}
Transaction::~Transaction()
{
  delete this->refBook;
}


string Transaction::getTransType() const
{
  return transType;
}
float Transaction::getTransAmount() const
{
  return transAmt;
}
Book* Transaction::getBook() const
{
  return refBook;
}
bool Transaction::getReturned() const
{
  return returned;
}

bool Transaction::setTransType(string transType)
{
  this->transType = transType;
  return true;
}
bool Transaction::setTransAmt(float transAmt)
{
  this->transAmt = transAmt;
  return true;
}
bool Transaction::setBook(Book* refBook)
{
  this->refBook = refBook;
  return true;
}
bool Transaction::setReturned(bool returned)
{
  this->returned = returned;
}

ostream& operator<<(ostream &outStream, Transaction* transToPrint)
{
  transToPrint->Print(outStream);
  return outStream;
}