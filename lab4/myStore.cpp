#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;
#include "BookStore.h"
const int MAX_LINE_SIZE = 2048;
const int MAX_TITLE = 512;

int main(int argc, char* argv[])
{
  BookStore myBookStore;
  fstream myFile;
  char line[MAX_LINE_SIZE];

  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " InventoryFilename CustomerFileName TransactionsFilename" << endl;
    return -1;
  }

  ///////////////////////////
  /////READ IN INVENTORY/////
  ///////////////////////////
  myFile.open(argv[1]);
  if (!myFile.is_open())
  {
    cerr << "File not found" << endl;
    return -1;
  }

  while (myFile.getline(line, MAX_LINE_SIZE))
  {
    stringstream ss;
    char token[MAX_TITLE];
    char bookType, newUsedType;
    int copies;
    string author, title;
    float cost;

    ss << line;
    ss.getline(token, MAX_TITLE, ',');
    bookType = token[0];
    ss.getline(token, MAX_TITLE, ',');
    newUsedType = token[0];
    ss.getline(token, MAX_TITLE, ',');
    copies = atof(token);
    ss.getline(token, MAX_TITLE, ',');
    author = (string)token;
    ss.getline(token, MAX_TITLE, ',');
    title = (string)token;
    ss.getline(token, MAX_TITLE, ',');
    cost = atof(token);

    switch (bookType)
    {
      case 'B':
      {
        if (newUsedType != 'N')
        {
          ss.getline(token, MAX_TITLE, ',');
          newUsedType = token[0];
        }
        string quality = string(1, newUsedType);

        Book* insBook = new Book(author, title, cost, quality);
        myBookStore.AddBook(insBook, copies);
        break;
      }
      case 'A':
      {
        string narrator;
        ss.getline(token, MAX_TITLE, ',');
        narrator = (string)token;

        if (newUsedType != 'N')
        {
          ss.getline(token, MAX_TITLE, ',');
          newUsedType = token[0];
        }
        string quality = string(1, newUsedType);

        AudioBook* insABook = new AudioBook(author, title, cost, narrator, quality);
        myBookStore.AddBook(insABook, copies);
        break;
      }
      case 'G':
      {
        string artist;
        ss.getline(token, MAX_TITLE, ',');
        artist = (string)token;

        if (newUsedType != 'N')
        {
          ss.getline(token, MAX_TITLE, ',');
          newUsedType = token[0];
        }
        string quality = string(1, newUsedType);

        GraphicNovel* insGNBook = new GraphicNovel(author, title, cost, artist, quality);
        myBookStore.AddBook(insGNBook, copies);
        break;
      }
      default:
      {
        cerr << "ERROR. Invalid Entry" << endl;
      }
    }
  }

  cout << myBookStore;

  ///////////////////////////
  /////READ IN CUSTOMERS/////
  ///////////////////////////


  return 0;


  Book book1, book2, book3("Frank", "Dune");
  GraphicNovel comic1;
  cout << "Welcome to the Library of Congress" << endl;
  book1.setTitle("The Dying Grass");
  book1.setAuthor("Vollmann");
  book1.setCost(55.00);

  comic1.setTitle("Watchmen");
  comic1.setAuthor("Moore");
  comic1.setArtist("Gibbons");
  comic1.setCost(22.99);

  book2 = (Book)comic1;
  book3 = comic1;

  cout << comic1 << endl;
  cout << book2 << endl;
  cout << book3 << endl;

  Book* pBook;
  pBook = &comic1;

  cout << *pBook << endl;
  pBook = &book1;

  cout << *pBook << endl;
  // comic1.PrintDetails(cout);
  // book2.PrintDetails(cout);
  return 0;

{

  fstream myFile;
  char line[MAX_LINE_SIZE];

  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " Filename" << endl;
    return -1;
  }
  myFile.open(argv[1]);
  if (!myFile.is_open())
  {
    cerr << "File not found" << endl;
    return -1;
  }

  while (myFile.getline(line, MAX_LINE_SIZE))
  {
    stringstream ss;
    char token[MAX_TITLE];
    vector<string> transactionData;
    ss << line;
    while (ss.getline(token, MAX_TITLE, ','))
    {
      string str(token);
      transactionData.push_back(str);
    }
    for (int i = 0; i < transactionData.size(); ++i)
    {
      cout << transactionData[i] << " ";
    }
    cout << endl;
    // transactionData.erase(transactionData.begin());
    // cout << transactionData.front() << endl;
  }

  return 0;
}

  // BookStore myBookStore;

  // GraphicNovel watchmen("whoKnows", "The Graphic Novel", 34.2, "allalal");
  // watchmen.setQuality("new");

  // AudioBook watchmen2("whoKnows", "TheWatchmen", 29, "Bill Nye", "excellent");

  // Book bible("god", "The Bible", 0  );
  // bible.setQuality("fair");

  // myBookStore.AddBook(&bible);
  // myBookStore.AddBook(&watchmen2);
  // myBookStore.AddBook(&watchmen);
  // myBookStore.AddBook(&watchmen2);
  // myBookStore.AddBook(&watchmen);
  // myBookStore.AddBook(&watchmen2);
  // myBookStore.AddBook(&watchmen);
  // // myBookStore.RemoveBook(bible, watchmen2);
  // // myBookStore.RemoveBook(bible, watchmen2);

  // cout << myBookStore;

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