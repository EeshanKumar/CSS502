#include "Book.h"

ostream& operator<<(ostream &outStream, const Book &bookToPrint)
{
  bookToPrint.print(outStream);
  return outStream;
}

void Book::print(ostream& outStream) const
{
  outStream << type << ": " << title << " by " << author << " (" << mapQuality(quality) << ") $" << cost << endl;
}

Book::Book()
{
  author = "";
  title = "";
  cost = 0;
  quality = New;
  type = "Book";
}
Book::Book(string author)
{
  this->author = author;
  title = "";
  cost = 0;
  quality = New;
  type = "Book";
}
Book::Book(string author, string title)
{
  this->author = author;
  this->title = title;
  cost = 0;
  quality = New;
  type = "Book";
}
Book::Book(string author, string title, float cost)
{
  this->author = author;
  this->title = title;
  this->cost = cost;
  quality = New;
  type = "Book";
}
Book::Book(string author, string title, float cost, string quality)
{
  this->author = author;
  this->title = title;
  this->cost = cost;
  this->setQuality(quality);
  type = "Book";
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
string Book::getQuality() const
{
  return mapQuality(quality);
}
string Book::getType() const
{
  return type;
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
  if (quality == "N" || quality == "new")
  {
    this->quality = New;
  }
  if (quality == "E" || quality == "excellent")
  {
    this->quality = Excellent;
  }
  if (quality == "G" || quality == "good")
  {
    this->quality = Good;
  }
  if (quality == "F" || quality == "fair")
  {
    this->quality = Fair;
  }
  return true;
}
bool Book::setType(string type)
{
  this->type = type;
  return true;
}

bool Book::operator<(Book rBook) const
{
  if (this->title == rBook.title)
  {
    if (this->type == rBook.type)
    {
      return this->quality < rBook.quality;
    }
    return this->type < rBook.type;
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
    if (this->type == rBook.type)
    {
      return this->quality > rBook.quality;
    }
    return this->type > rBook.type;
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
  return (this->title == rBook.title) && (this->quality == rBook.quality) && (this->type == rBook.type);
}
bool Book::operator!=(Book rBook) const
{
  return (this->title != rBook.title) || (this->quality != rBook.quality) || (this->type != rBook.type);
}

string Book::mapQuality(Quality quality) const
{
  switch (quality)
  {
    case 0:
      return "New";
    case 1:
      return "Excellent";
    case 2:
      return "Good";
    case 3:
      return "Fair";
    default:
      return "Error";
  }
}