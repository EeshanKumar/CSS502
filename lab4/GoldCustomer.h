#include "Customer.h"

#ifndef GOLDCUSTOMER_H
#define GOLDCUSTOMER_H

class GoldCustomer: public Customer
{
public:
  GoldCustomer();
  GoldCustomer(string firstName);
  GoldCustomer(string firstName, string lastName);
  GoldCustomer(string firstName, string lastName, int age);
  GoldCustomer(string firstName, string lastName, int age, float amtSpent);
  ~GoldCustomer();

  float applyDiscount(float cost) const;
};

#endif //GOLDCUSTOMER_H