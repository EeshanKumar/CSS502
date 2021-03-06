#include "SeniorCustomer.h"

SeniorCustomer::SeniorCustomer()
{
  this->status = "senior";
}
SeniorCustomer::SeniorCustomer(string firstName): Customer(firstName)
{
  this->status = "senior";
}
SeniorCustomer::SeniorCustomer(string firstName, string lastName): Customer(firstName, lastName)
{
  this->status = "senior";
}
SeniorCustomer::SeniorCustomer(string firstName, string lastName, int age): Customer(firstName, lastName, age)
{
  this->status = "senior";
}
SeniorCustomer::SeniorCustomer(string firstName, string lastName, int age, float amtSpent): Customer(firstName, lastName, age, amtSpent)
{
  this->status = "senior";
}
SeniorCustomer::~SeniorCustomer()
{
}

float SeniorCustomer::applyDiscount(float cost, string type) const
{
  return round(100 * cost * 0.85) / 100;
}