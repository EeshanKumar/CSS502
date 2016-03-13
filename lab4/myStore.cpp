#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
#include "BookStore.h"
const int MAX_LINE_SIZE = 2048;
const int MAX_TITLE = 512;


// trim from end
static inline string &rtrim(string &s) {
        s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
        return s;
}

int main(int argc, char* argv[])
{
  BookStore myBookStore(&cout);
  fstream inventoryFile;
  fstream customerFile;
  fstream transactionFile;
  char line[MAX_LINE_SIZE];

  if (argc != 4)
  {
    cerr << "Usage: " << argv[0] << " InventoryFilename CustomerFileName TransactionsFilename" << endl;
    return -1;
  }

  ///////////////////////////
  /////READ IN INVENTORY/////
  ///////////////////////////
  inventoryFile.open(argv[1]);
  if (!inventoryFile.is_open())
  {
    cerr << "Inventory File not found" << endl;
    return -1;
  }

  while (inventoryFile.getline(line, MAX_LINE_SIZE))
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
        Book* insBook = insABook;
        myBookStore.AddBook(insBook, copies);
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
        Book* insBook = insGNBook;
        myBookStore.AddBook(insBook, copies);
        break;
      }
      default:
      {
        cerr << "ERROR. Invalid Entry" << endl;
      }
    }
  }

  ///////////////////////////
  /////READ IN CUSTOMERS/////
  ///////////////////////////
  customerFile.open(argv[2]);
  if (!customerFile.is_open())
  {
    cerr << "Customer File not found" << endl;
    return -1;
  }

  while (customerFile.getline(line, MAX_LINE_SIZE))
  {
    stringstream ss;
    char token[MAX_TITLE];
    string firstName, lastName;
    int age;

    ss << line;
    ss.getline(token, MAX_TITLE, ',');
    firstName = (string)token;
    ss.getline(token, MAX_TITLE, ',');
    lastName = (string)token;
    ss.getline(token, MAX_TITLE, ',');
    age = atoi(token);

    Customer* insCustomer = new Customer(firstName, lastName, age);

    // if (age > 65) {
    //   SeniorCustomer* myCustomer = new SeniorCustomer(firstName, lastName, age);
    //   insCustomer = myCustomer;
    // }
    // else
    // {
      // insCustomer = new Customer(firstName, lastName, age);o
    // }
    myBookStore.AddCustomer(insCustomer);
  }


  ////////////////////////////////////////
  /////READ IN + PROCESS TRANSACTIONS/////
  ////////////////////////////////////////
  transactionFile.open(argv[3]);
  if (!transactionFile.is_open())
  {
    cerr << "File not found" << endl;
    return -1;
  }

  while (transactionFile.getline(line, MAX_LINE_SIZE))
  {
    stringstream ss;
    char token[MAX_TITLE];
    char transType;

    ss << line;
    ss.getline(token, MAX_TITLE, ',');
    transType = token[0];


    switch (transType)
    {
      case 'I':
      {
        myBookStore.PrintInventory();
        break;
      }
      case 'H':
      {
        string custFirstName, custLastName;
        Customer myCustomer;

        ss.getline(token, MAX_TITLE, ',');
        custFirstName = (string)token;
        myCustomer.setFirstName(custFirstName);
        ss.getline(token, MAX_TITLE, ',');
        custLastName = (string)token;
        custLastName = rtrim(custLastName);
        myCustomer.setLastName(custLastName);

        myBookStore.PrintCustomerHistory(myCustomer);
        break;
      }
      case 'P':
      {
        string custFirstName, custLastName;
        Customer myCustomer;
        char bookType, newUsedType;
        string author, title;

        ss.getline(token, MAX_TITLE, ',');
        custFirstName = (string)token;
        myCustomer.setFirstName(custFirstName);
        ss.getline(token, MAX_TITLE, ',');
        custLastName = (string)token;
        myCustomer.setLastName(custLastName);

        ss.getline(token, MAX_TITLE, ',');
        bookType = token[0];
        ss.getline(token, MAX_TITLE, ',');
        newUsedType = token[0];
        ss.getline(token, MAX_TITLE, ',');
        author = (string)token;
        ss.getline(token, MAX_TITLE, ',');
        title = (string)token;
        title = rtrim(title);

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

            Book* myBook = new Book(author, title);
            myBook->setQuality(quality);

            //Do Stuff with myBook
            myBookStore.ProcessPurchase(myCustomer, myBook);
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

            AudioBook* myAudioBook = new AudioBook(author, title);
            myAudioBook->setNarrator(narrator);
            myAudioBook->setQuality(quality);

            Book* myBook = myAudioBook;

            //Do Stuff with myBook
            myBookStore.ProcessPurchase(myCustomer, myBook);
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

            GraphicNovel* myGraphicNovel = new GraphicNovel(author, title);
            myGraphicNovel->setArtist(artist);
            myGraphicNovel->setQuality(quality);

            Book* myBook = myGraphicNovel;

            //Do Stuff with myBook
            myBookStore.ProcessPurchase(myCustomer, myBook);
            break;
          }
          default:
          {
            cerr << "ERROR. Invalid Entry" << endl;
          }
        }
        break;
      }
      case 'R':
      {
        string custFirstName, custLastName;
        Customer myCustomer;
        char bookType, newUsedType;
        string author, title;

        ss.getline(token, MAX_TITLE, ',');
        custFirstName = (string)token;
        myCustomer.setFirstName(custFirstName);
        ss.getline(token, MAX_TITLE, ',');
        custLastName = (string)token;
        myCustomer.setLastName(custLastName);

        ss.getline(token, MAX_TITLE, ',');
        bookType = token[0];
        ss.getline(token, MAX_TITLE, ',');
        newUsedType = token[0];
        ss.getline(token, MAX_TITLE, ',');
        author = (string)token;
        ss.getline(token, MAX_TITLE, ',');
        title = (string)token;
        title = rtrim(title);

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

            Book* myBook = new Book(author, title);
            myBook->setQuality(quality);
            Book* myCopiedBook = new Book(author, title);
            myCopiedBook->setQuality(quality);

            //Do Stuff with myBook
            myBookStore.ProcessReturn(myCustomer, myBook, myCopiedBook);
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

            AudioBook* myAudioBook = new AudioBook(author, title);
            myAudioBook->setNarrator(narrator);
            myAudioBook->setQuality(quality);
            AudioBook* myCopiedAudioBook = new AudioBook(author, title);
            myCopiedAudioBook->setNarrator(narrator);
            myCopiedAudioBook->setQuality(quality);

            Book* myBook = myAudioBook;
            Book* myCopiedBook = myCopiedAudioBook;

            //Do Stuff with myBook
            myBookStore.ProcessReturn(myCustomer, myBook, myCopiedBook);
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

            GraphicNovel* myGraphicNovel = new GraphicNovel(author, title);
            myGraphicNovel->setArtist(artist);
            myGraphicNovel->setQuality(quality);
            GraphicNovel* myCopiedGraphicNovel = new GraphicNovel(author, title);
            myCopiedGraphicNovel->setArtist(artist);
            myCopiedGraphicNovel->setQuality(quality);

            Book* myBook = myGraphicNovel;
            Book* myCopiedBook = myCopiedGraphicNovel;

            //Do Stuff with myBook
            myBookStore.ProcessReturn(myCustomer, myBook, myCopiedBook);
            break;
          }
          default:
          {
            cerr << "ERROR. Invalid Entry" << endl;
          }
        }
        break;
      }
      case 'T':
      {
        string custFirstName, custLastName;
        Customer myCustomer;
        char bookType, newUsedType;
        string author, title;
        float cost;

        ss.getline(token, MAX_TITLE, ',');
        custFirstName = (string)token;
        myCustomer.setFirstName(custFirstName);
        ss.getline(token, MAX_TITLE, ',');
        custLastName = (string)token;
        myCustomer.setLastName(custLastName);

        ss.getline(token, MAX_TITLE, ',');
        bookType = token[0];
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
            ss.getline(token, MAX_TITLE, ',');
            newUsedType = token[0];
            string quality = string(1, newUsedType);

            Book* myBook = new Book(author, title, cost, quality);
            Book* myCopiedBook = new Book(author, title, cost, quality);

            //Do Stuff with myBook
            myBookStore.ProcessTradeIn(myCustomer, myBook, myCopiedBook);
            break;
          }
          case 'A':
          {
            string narrator;
            ss.getline(token, MAX_TITLE, ',');
            narrator = (string)token;

            ss.getline(token, MAX_TITLE, ',');
            newUsedType = token[0];
            string quality = string(1, newUsedType);

            AudioBook* myAudioBook = new AudioBook(author, title, cost, narrator, quality);
            AudioBook* myCopiedAudioBook = new AudioBook(author, title, cost, narrator, quality);

            Book* myBook = myAudioBook;
            Book* myCopiedBook = myCopiedAudioBook;

            //Do Stuff with myBook
            myBookStore.ProcessTradeIn(myCustomer, myBook, myCopiedBook);
            break;
          }
          case 'G':
          {
            string artist;
            ss.getline(token, MAX_TITLE, ',');
            artist = (string)token;

            ss.getline(token, MAX_TITLE, ',');
            newUsedType = token[0];
            string quality = string(1, newUsedType);

            GraphicNovel* myGraphicNovel = new GraphicNovel(author, title, cost, artist, quality);
            GraphicNovel* myCopiedGraphicNovel = new GraphicNovel(author, title, cost, artist, quality);

            Book* myBook = myGraphicNovel;
            Book* myCopiedBook = myCopiedGraphicNovel;

            //Do Stuff with myBook
            myBookStore.ProcessTradeIn(myCustomer, myBook, myCopiedBook);
            break;
          }
          default:
          {
            cerr << "ERROR. Invalid Entry" << endl;
          }
        }
        break;
      }
      default:
      {
        cerr << "ERROR. Invalid Transaction Entry" << endl;
      }
    }
  }

  cout << myBookStore.getBalance();
  return 0;
}