#include <iostream>
#include <string>
using namespace std;

#ifndef BOOK_H
#define BOOK_H

class Book
{
friend ostream& operator<<(ostream &outStream, const Book &bookToPrint);

public:
  enum Quality { New, Excellent, Good, Fair };

  Book();
  Book(string author);
  Book(string author, string title);
  Book(string author, string title, float cost);
  Book(string author, string title, float cost, string quality);
  virtual ~Book();

  string getAuthor() const;
  string getTitle() const;
  float getCost() const;
  int getQuality() const;

  bool setAuthor(string author);
  bool setTitle(string title);
  bool setCost(float cost);
  bool setQuality(string quality);

  bool operator<(Book rBook) const;
  bool operator<=(Book rBook) const;
  bool operator>(Book rBook) const;
  bool operator>=(Book rBook) const;
  bool operator==(Book rBook) const;
  bool operator!=(Book rBook) const;

  virtual void print(ostream& outStream) const;

protected:
  string title;
  string author;
  float cost;
  Quality quality;
};

#endif //BOOK_H