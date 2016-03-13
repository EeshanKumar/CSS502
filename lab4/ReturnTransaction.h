#include "Transaction.h"

#ifndef RETURNTRANSACTION_H
#define RETURNTRANSACTION_H

class ReturnTransaction: public Transaction
{
  friend ostream& operator<<(ostream &outStream, ReturnTransaction transToPrint);

public:
  ReturnTransaction();
  ReturnTransaction(string transType);
  ReturnTransaction(string transType, float transAmt);
  ReturnTransaction(string transType, float transAmt, Book* refBook);
  ~ReturnTransaction();

  void Print(ostream &outStream) const;
};

#endif //RETURNTRANSACTION_H