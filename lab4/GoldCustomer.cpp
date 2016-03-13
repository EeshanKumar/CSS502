#include "GoldCustomer.h"

GoldCustomer::GoldCustomer()
{
}
GoldCustomer::GoldCustomer(string firstName): Customer(firstName)
{
}
GoldCustomer::GoldCustomer(string firstName, string lastName): Customer(firstName, lastName)
{
}
GoldCustomer::GoldCustomer(string firstName, string lastName, int age): Customer(firstName, lastName, age)
{
}
GoldCustomer::GoldCustomer(string firstName, string lastName, int age, float amtSpent): Customer(firstName, lastName, age, amtSpent)
{
}
GoldCustomer::~GoldCustomer()
{
  for (int i = 0; i < history.size(); ++i)
  {
     delete history[i];
  }
}

float GoldCustomer::applyDiscount(float cost) const
{
  return cost * 0.9;
}