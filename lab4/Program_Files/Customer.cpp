#include "Customer.h"

ostream& operator<<(ostream &outStream, const Customer &customerToPrint)
{
  outStream << customerToPrint.firstName << " " << customerToPrint.lastName << " " << customerToPrint.age << endl;
}

Customer::Customer()
{
  this->status = "normal";
}
Customer::Customer(string firstName)
{
  this->firstName = firstName;
  this->status = "normal";
}
Customer::Customer(string firstName, string lastName)
{
  this->firstName = firstName;
  this->lastName = lastName;
  this->status = "normal";
}
Customer::Customer(string firstName, string lastName, int age)
{
  this->firstName = firstName;
  this->lastName = lastName;
  this->age = age;
  this->status = "normal";
}
Customer::Customer(string firstName, string lastName, int age, float amtSpent)
{
  this->firstName = firstName;
  this->lastName = lastName;
  this->age = age;
  this->amtSpent = amtSpent;
  this->status = "normal";
}
Customer::~Customer()
{
  for (int i = 0; i < history.size(); ++i)
  {
     delete history[i];
  }
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
string Customer::getStatus() const
{
  return status;
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
bool Customer::setStatus(string status)
{
  this->status = status;
  return true;
}

bool Customer::AddTransactionToHistory(Transaction* trans)
{
  history.push_back(trans);
}

bool Customer::operator==(Customer rhs) const
{
  return ((firstName == rhs.firstName) && (lastName == rhs.lastName) && (age == rhs.age) && (amtSpent == rhs.amtSpent));
}
bool Customer::operator!=(Customer rhs) const
{
  return ((firstName != rhs.firstName) || (lastName != rhs.lastName) || (age != rhs.age) || (amtSpent != rhs.amtSpent));
}

float Customer::IncrementAndReturnAmtSpent(float amount)
{
  amtSpent += amount;
  return amtSpent;
}

float Customer::ReturnCostOfPurchasedBook(Book* returnedBook)
{
  for (int i = 0; i < history.size(); ++i)
  {
    if ((history[i]->getTransType() == "Purchase") && (*(history[i]->getBook()) == *returnedBook) && (!history[i]->getReturned()))
    {
      history[i]->setReturned(true);
      return history[i]->getTransAmount();
    }
  }
  return -1;
}

void Customer::PrintHistory(ostream& outStream) const
{
  outStream << "Customer History for ";
  outStream << firstName << " " << lastName << endl;
  for (int i = 0; i < history.size(); ++i)
  {
    outStream << history[i];
  }
  outStream << endl;
}

float Customer::applyDiscount(float cost, string type) const
{
  if (status == "gold" && type != "AudioBook")
  {
    return round(100 * cost * 0.9) / 100;
  }
  return cost;
}