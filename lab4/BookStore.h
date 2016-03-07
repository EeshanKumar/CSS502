#include <iostream>
#include "Book.h"
#include "GraphicNovel.h"
#include "AudioBook.h"
#include "BST.h"

#ifndef BOOKSTORE_H
#define BOOKSTORE_H

class BookStore
{
friend ostream& operator<<(ostream &outStream, const BookStore &bookStoreToPrint);

public:
  BookStore();
  ~BookStore();

  bool AddBook(Book* insBook);
  bool RemoveBook(Book target, Book &removedBook);

private:
  BST<Book> inventory;
};

#endif //BOOKSTORE_H