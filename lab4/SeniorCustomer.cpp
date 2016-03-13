#include "SeniorCustomer.h"

SeniorCustomer::SeniorCustomer()
{
}
SeniorCustomer::SeniorCustomer(string firstName): Customer(firstName)
{
}
SeniorCustomer::SeniorCustomer(string firstName, string lastName): Customer(firstName, lastName)
{
}
SeniorCustomer::SeniorCustomer(string firstName, string lastName, int age): Customer(firstName, lastName, age)
{
}
SeniorCustomer::SeniorCustomer(string firstName, string lastName, int age, float amtSpent): Customer(firstName, lastName, age, amtSpent)
{
}
SeniorCustomer::~SeniorCustomer()
{
}

float SeniorCustomer::applyDiscount(float cost) const
{
  return cost * 0.85;
}