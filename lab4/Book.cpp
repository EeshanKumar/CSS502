#include "Book.h"

ostream& operator<<(ostream &outStream, const Book &bookToPrint)
{
  bookToPrint.print(outStream);
  return outStream;
}

void Book::print(ostream& outStream) const
{
  outStream << "Author: " << author << endl;
  outStream << "Title: " << title << endl;
  outStream << "Cost: $" << cost << endl;
  outStream << "Quality: " << quality << endl;
}

Book::Book()
{
  author = "";
  title = "";
  cost = 0;
}
Book::Book(string author)
{
  this->author = author;
  title = "";
  cost = 0;
}
Book::Book(string author, string title)
{
  this->author = author;
  this->title = title;
  cost = 0;
}
Book::Book(string author, string title, float cost)
{
  this->author = author;
  this->title = title;
  this->cost = cost;
}
Book::Book(string author, string title, float cost, string quality)
{
  this->author = author;
  this->title = title;
  this->cost = cost;
  this->setQuality(quality);
}
Book::~Book()
{
}

string Book::getAuthor() const
{
  return author;
}
string Book::getTitle() const
{
  return title;
}
float Book::getCost() const
{
  return cost;
}
int Book::getQuality() const
{
  return quality;
}

bool Book::setAuthor(string author)
{
  this->author = author;
  return true;
}
bool Book::setTitle(string title)
{
  this->title = title;
  return true;
}
bool Book::setCost(float cost)
{
  this->cost = cost;
  return true;
}
bool Book::setQuality(string quality)
{
  if (quality == "n" || quality == "new")
  {
    this->quality = New;
  }
  if (quality == "e" || quality == "excellent")
  {
    this->quality = Excellent;
  }
  if (quality == "g" || quality == "good")
  {
    this->quality = Good;
  }
  if (quality == "f" || quality == "fair")
  {
    this->quality = Fair;
  }
  return true;
}

bool Book::operator<(Book rBook) const
{
  if (this->title == rBook.title)
  {
    return this->quality < rBook.quality;
  }
  return this->title < rBook.title;
}
bool Book::operator<=(Book rBook) const
{
  if (*this == rBook)
  {
    return true;
  }
  return *this < rBook;
}
bool Book::operator>(Book rBook) const
{
  if (this->title == rBook.title)
  {
    return this->quality > rBook.quality;
  }
  return this->title > rBook.title;
}
bool Book::operator>=(Book rBook) const
{
  if (*this == rBook)
  {
    return true;
  }
  return *this > rBook;
}
bool Book::operator==(Book rBook) const
{
  return (this->title == rBook.title) && (this->quality == rBook.quality);
}
bool Book::operator!=(Book rBook) const
{
  return (this->title != rBook.title) || (this->quality != rBook.quality);
}