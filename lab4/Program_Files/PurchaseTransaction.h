#include "Transaction.h"

#ifndef PURCHASETRANSACTION_H
#define PURCHASETRANSACTION_H

class PurchaseTransaction: public Transaction
{
  friend ostream& operator<<(ostream &outStream, PurchaseTransaction transToPrint);

public:
  PurchaseTransaction();
  PurchaseTransaction(string transType);
  PurchaseTransaction(string transType, float transAmt);
  PurchaseTransaction(string transType, float transAmt, Book* refBook);
  ~PurchaseTransaction();

  void Print(ostream &outStream) const;

private:
  bool returned = false;
};

#endif //PURCHASETRANSACTION_H