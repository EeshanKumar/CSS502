#include "Customer.h"

ostream& operator<<(ostream &outStream, const Customer &customerToPrint)
{
  outStream << customerToPrint.firstName << " " << customerToPrint.lastName << " " << customerToPrint.age << endl;
}

Customer::Customer()
{
}
Customer::Customer(string firstName)
{
  this->firstName = firstName;
}
Customer::Customer(string firstName, string lastName)
{
  this->firstName = firstName;
  this->lastName = lastName;
}
Customer::Customer(string firstName, string lastName, int age)
{
  this->firstName = firstName;
  this->lastName = lastName;
  this->age = age;
}
Customer::Customer(string firstName, string lastName, int age, float amtSpent)
{
  this->firstName = firstName;
  this->lastName = lastName;
  this->age = age;
  this->amtSpent = amtSpent;
}
Customer::~Customer()
{
}

string Customer::getFirstName() const
{
  return firstName;
}
string Customer::getLastName() const
{
  return lastName;
}
int Customer::getAge() const
{
  return age;
}
float Customer::getAmtSpent() const
{
  return amtSpent;
}

bool Customer::setFirstName(string firstName)
{
  this->firstName = firstName;
  return true;
}
bool Customer::setLastName(string lastName)
{
  this->lastName = lastName;
  return true;
}
bool Customer::setAge(int age)
{
  this->age = age;
  return true;
}
bool Customer::setAmtSpent(float amtSpent)
{
  this->amtSpent = amtSpent;
  return true;
}

bool Customer::operator==(Customer rhs) const
{
  return ((firstName == rhs.firstName) && (lastName == rhs.lastName) && (age == rhs.age) && (amtSpent == rhs.amtSpent));
}
bool Customer::operator!=(Customer rhs) const
{
  return ((firstName != rhs.firstName) || (lastName != rhs.lastName) || (age != rhs.age) || (amtSpent != rhs.amtSpent));
}

float Customer::incrementAndReturnAmtSpent(float amount)
{
  amtSpent += amount;
  return amtSpent;
}

void Customer::PrintHistory(ostream& outStream) const
{
  outStream << "Customer History for ";
  outStream << firstName << " " << lastName << endl;
  for (int i = 0; i < history.size(); ++i)
  {
    outStream << history[i] << endl;
  }
}

float Customer::applyDiscount(float cost) const
{
  return cost;
}