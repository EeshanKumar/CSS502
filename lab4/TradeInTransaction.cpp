#include "TradeInTransaction.h"

TradeInTransaction::TradeInTransaction()
{
}
TradeInTransaction::TradeInTransaction(string transType): Transaction(transType)
{
}
TradeInTransaction::TradeInTransaction(string transType, float transAmt): Transaction(transType, transAmt)
{
}
TradeInTransaction::TradeInTransaction(string transType, float transAmt, Book* refBook): Transaction(transType, transAmt, refBook)
{
}
TradeInTransaction::~TradeInTransaction()
{
  delete this->refBook;
}

void TradeInTransaction::Print(ostream &outStream) const
{
  outStream << "Printed Trade In Transaction Here" << endl;
}

ostream& operator<<(ostream &outStream, TradeInTransaction transToPrint)
{
  transToPrint.Print(outStream);
  return outStream;
}