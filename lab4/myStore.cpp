#include <iostream>
using namespace std;
#include "BookStore.h"

int main(int argc, char* argv[])
{
  BookStore myBookStore;

  GraphicNovel watchmen("whoKnows", "The Graphic Novel", 34.2, "allalal");
  watchmen.setQuality("new");

  AudioBook watchmen2("whoKnows", "TheWatchmen", 29, "Bill Nye", "excellent");

  Book bible("god", "The Bible", 0  );
  bible.setQuality("fair");

  myBookStore.AddBook(&bible);
  myBookStore.AddBook(&watchmen2);
  myBookStore.AddBook(&watchmen);
  myBookStore.AddBook(&watchmen2);
  myBookStore.AddBook(&watchmen);
  myBookStore.AddBook(&watchmen2);
  myBookStore.AddBook(&watchmen);
  // myBookStore.RemoveBook(bible, watchmen2);
  // myBookStore.RemoveBook(bible, watchmen2);

  cout << myBookStore;

  // Book* myBook = new AudioBook(watchmen2);

  // cout << *myBook << endl;

  // if (watchmen2 > watchmen)
  // {
  //   cout << "watchmen2 > watchmen" << endl;
  // }
  // if (watchmen2 >= watchmen)
  // {
  //   cout << "watchmen2 >= watchmen" << endl;
  // }
  // if (watchmen2 < watchmen)
  // {
  //   cout << "watchmen2 < watchmen" << endl;
  // }
  // if (watchmen2 <= watchmen)
  // {
  //   cout << "watchmen2 <= watchmen" << endl;
  // }
  // if (bible > watchmen)
  // {
  //   cout << "bible > watchmen" << endl;
  // }
  // if (bible >= watchmen)
  // {
  //   cout << "bible >= watchmen" << endl;
  // }
  // if (bible < watchmen)
  // {
  //   cout << "bible < watchmen" << endl;
  // }
  // if (bible <= watchmen)
  // {
  //   cout << "bible <= watchmen" << endl;
  // }

  return 0;
}