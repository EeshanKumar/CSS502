#include "BookStore.h"

ostream& operator<<(ostream &outStream, const BookStore &bookStoreToPrint)
{
  outStream << bookStoreToPrint.inventory;
}

BookStore::BookStore()
{
}
BookStore::~BookStore()
{
}

bool BookStore::AddBook(Book* insBook, int copies)
{
  inventory.Insert(insBook, copies);
  return true;
}
bool BookStore::RemoveBook(Book* target, Book &removedBookPointer)
{
  int copiesLeft;
  copiesLeft = inventory.RemoveOrDecrement(*target, removedBookPointer);
  if (copiesLeft == -1) {
    return false;
  }
  return true;
}