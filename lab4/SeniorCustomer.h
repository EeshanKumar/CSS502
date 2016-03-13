#include "Customer.h"

#ifndef SENIORCUSTOMER_H
#define SENIORCUSTOMER_H

class SeniorCustomer: public Customer
{
public:
  SeniorCustomer();
  SeniorCustomer(string firstName);
  SeniorCustomer(string firstName, string lastName);
  SeniorCustomer(string firstName, string lastName, int age);
  SeniorCustomer(string firstName, string lastName, int age, float amtSpent);
  ~SeniorCustomer();

  float applyDiscount(float cost) const;
};

#endif //SENIORCUSTOMER_H