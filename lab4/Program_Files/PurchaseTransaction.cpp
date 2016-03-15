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
  if (transAmt == refBook->getCost())
  {
    outStream << transType << " Transaction: Bought " << refBook->getTitle() << " for $" << transAmt << endl;
    return;
  }
  outStream << transType << " Transaction: Bought " << refBook->getTitle() << " for $" << transAmt << " discounted from $" << refBook->getCost() << endl;
}

ostream& operator<<(ostream &outStream, PurchaseTransaction transToPrint)
{
  transToPrint.Print(outStream);
  return outStream;
}