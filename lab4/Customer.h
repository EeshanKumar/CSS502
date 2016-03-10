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
  Customer(string firstName, string lastName, int age, int amtSpent);
  ~Customer();

  string getFirstName() const;
  string getLastName() const;
  int getAge() const;
  int getAmtSpent() const;

  bool setFirstName(string firstName);
  bool setLastName(string lastName);
  bool setAge(int age);
  bool setAmtSpent(int amtSpent);

  bool operator==(Customer rhs) const;
  bool operator!=(Customer rhs) const;

  bool incrementAmtSpent(float amount);

  void PrintHistory(ostream& outStream) const;

private:
  string firstName;
  string lastName;
  int age;
  int amtSpent = 0; //Can be negative (Customer has traded in more than they have purchsed)
  vector<Transaction> history;
};

#endif //CUSTOMER_H