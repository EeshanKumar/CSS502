#include "Transaction.h"

#ifndef TRADEINTRANSACTION_H
#define TRADEINTRANSACTION_H

class TradeInTransaction: public Transaction
{
  friend ostream& operator<<(ostream &outStream, TradeInTransaction transToPrint);

public:
  TradeInTransaction();
  TradeInTransaction(string transType);
  TradeInTransaction(string transType, float transAmt);
  TradeInTransaction(string transType, float transAmt, Book* refBook);
  ~TradeInTransaction();

  void Print(ostream &outStream) const;
};

#endif //TRADEINTRANSACTION_H