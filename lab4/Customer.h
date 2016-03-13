#include <iostream>
#include <vector>
using namespace std;
#include "Transaction.h"

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
  friend ostream& operator<<(ostream &outStream, const Customer &customerToPrint);

public:
  Customer();
  Customer(string firstName);
  Customer(string firstName, string lastName);
  Customer(string firstName, string lastName, int age);
  Customer(string firstName, string lastName, int age, float amtSpent);
  virtual ~Customer();

  string getFirstName() const;
  string getLastName() const;
  int getAge() const;
  float getAmtSpent() const;
  string getStatus() const;

  bool setFirstName(string firstName);
  bool setLastName(string lastName);
  bool setAge(int age);
  bool setAmtSpent(float amtSpent);
  bool setStatus(string status);

  bool operator==(Customer rhs) const;
  bool operator!=(Customer rhs) const;

  float IncrementAndReturnAmtSpent(float amount);
  float ReturnCostOfPurchasedBook(Book* returnedBook);

  bool AddTransactionToHistory(Transaction* trans);
  void PrintHistory(ostream& outStream) const;

  virtual float applyDiscount(float cost) const;

protected:
  string firstName;
  string lastName;
  int age;
  float amtSpent = 0; //Can be negative (Customer has traded in more than they have purchsed)
  string status = "normal";
  vector<Transaction*> history;
};

#endif //CUSTOMER_H