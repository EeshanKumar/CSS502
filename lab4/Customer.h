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
  Customer(string firstName, string lastName, int age, int balance);
  ~Customer();

  string getFirstName() const;
  string getLastName() const;
  int getAge() const;
  int getBalance() const;

  bool setFirstName(string firstName);
  bool setLastName(string lastName);
  bool setAge(int age);
  bool setBalance(int balance);

  bool operator==(Customer rhs) const;
  bool operator!=(Customer rhs) const;

private:
  string firstName;
  string lastName;
  int age;
  int balance = 0;
  vector<Transaction> history;
};

#endif //CUSTOMER_H