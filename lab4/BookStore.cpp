#include "BookStore.h"

ostream& operator<<(ostream &outStream, const BookStore &bookStoreToPrint)
{
  outStream << bookStoreToPrint.inventory << endl;
}

BookStore::BookStore()
{
}
BookStore::~BookStore()
{
}

bool BookStore::AddBook(Book* insBook)
{
  inventory.InsertOrIncrement(insBook);
  return true;
}
bool BookStore::RemoveBook(Book target, Book &removedBook)
{
  int copiesLeft;
  copiesLeft = inventory.RemoveOrDecrement(target, removedBook);
  if (copiesLeft == -1) {
    return false;
  }
  return true;
}