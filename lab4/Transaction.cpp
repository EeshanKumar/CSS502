#include "Transaction.h"

ostream& operator<<(ostream &outStream, Transaction transToPrint)
{
  outStream << "Printed Transaction Here" << endl;
  return outStream;
}

Transaction::Transaction()
{
}
Transaction::~Transaction()
{
}
