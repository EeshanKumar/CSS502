#include <iostream>
using namespace std;

#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction
{
  friend ostream& operator<<(ostream &outStream, Transaction transToPrint);

public:
  Transaction();
  ~Transaction();

private:

};

#endif //TRANSACTION_H