#include "ReturnTransaction.h"

ReturnTransaction::ReturnTransaction()
{
}
ReturnTransaction::ReturnTransaction(string transType): Transaction(transType)
{
}
ReturnTransaction::ReturnTransaction(string transType, float transAmt): Transaction(transType, transAmt)
{
}
ReturnTransaction::ReturnTransaction(string transType, float transAmt, Book* refBook): Transaction(transType, transAmt, refBook)
{
}
ReturnTransaction::~ReturnTransaction()
{
  delete this->refBook;
}

void ReturnTransaction::Print(ostream &outStream) const
{
  outStream << transType << " Transaction: Returned " << refBook->getTitle() << " for $" << transAmt << endl;
}

ostream& operator<<(ostream &outStream, ReturnTransaction transToPrint)
{
  transToPrint.Print(outStream);
  return outStream;
}