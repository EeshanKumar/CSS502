#include "PurchaseTransaction.h"

PurchaseTransaction::PurchaseTransaction()
{
}
PurchaseTransaction::PurchaseTransaction(string transType): Transaction(transType)
{
}
PurchaseTransaction::PurchaseTransaction(string transType, float transAmt): Transaction(transType, transAmt)
{
}
PurchaseTransaction::PurchaseTransaction(string transType, float transAmt, Book* refBook): Transaction(transType, transAmt, refBook)
{
}
PurchaseTransaction::~PurchaseTransaction()
{
  delete this->refBook;
}

void PurchaseTransaction::Print(ostream &outStream) const
{
  outStream << transType << " Transaction: Bought " << refBook->getTitle() << " for $" << transAmt << endl;
}

ostream& operator<<(ostream &outStream, PurchaseTransaction transToPrint)
{
  transToPrint.Print(outStream);
  return outStream;
}