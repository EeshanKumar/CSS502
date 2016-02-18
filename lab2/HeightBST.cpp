#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "BST.h"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    cout << "Input a file name as an argument" << endl;
    return 0;
  }

  BST<string> myStringTree;
  ifstream inputFile;
  string fileName = argv[1];

  inputFile.open(fileName.c_str());
  while (inputFile.is_open())
  {
    // Take in next string
    string nextWord;
    inputFile >> nextWord;

    if (inputFile.eof())
    {
      inputFile.close();
      continue;
    }
    string *insWord = new string(nextWord);
    myStringTree.InsertOrIncrement(insWord);
    delete insWord;
  }

  cout << "Strings in order:" << endl;
  cout << myStringTree << endl;
  cout << "Height of tree: " << myStringTree.Height() << endl;

  return 0;

  //TESTING FUNCTIONS

  // cout << myStringTree << endl;

  // cout << "Height of tree is " << myStringTree.Height() << endl;

  // BST<string> newTree = myStringTree;
  // cout << "NEW TREE" << endl;
  // cout << newTree << endl;

  // myStringTree += newTree;

  // string removeWord = "is";
  // string removedWord;
  // int newCount;

  // do
  // {
  // newCount = myStringTree.RemoveOrDecrement(removeWord, removedWord);
  // cout << "Removed '" << removedWord << "' with newCount = " << newCount << endl;
  // } while (newCount != -1);

  // cout << myStringTree << endl;

  // cout << "Height of tree is " << myStringTree.Height() << endl;

  // newTree = myStringTree;
  // cout << "NEW TREE" << endl;
  // cout << newTree << endl;

  // string are = "are";
  // cout << "Count of 'are' = " << myStringTree.Count(are) << endl;
  // string is = "is";
  // cout << "Count of 'is' = " << myStringTree.Count(is) << endl;
  // string isdfasdfwes = "isdfasdfwes";
  // cout << "Count of 'isdfasdfwes' = " << myStringTree.Count(isdfasdfwes) << endl;

  // myStringTree.ClearTree();

  // cout << "isEmpty? " << myStringTree.isEmpty() << endl;
  // cout << myStringTree << endl;

  // cout << "Height of tree is " << myStringTree.Height() << endl;

  // newTree = myStringTree;
  // cout << "NEW TREE" << endl;
  // cout << newTree << endl;

  // string test = "Test";
  // string * insWord = new string(test);
  // myStringTree.InsertOrIncrement(insWord);
  // delete insWord;

  // cout << "isEmpty? " << myStringTree.isEmpty() << endl;

  // cout << myStringTree << endl;

  // cout << "Height of tree is " << myStringTree.Height() << endl;

  // newTree = myStringTree;
  // cout << "NEW TREE" << endl;
  // cout << newTree << endl;

  // BST<string> addTree;
  // string addString = "word";
  // string * addInsString = new string(addString);
  // addTree.InsertOrIncrement(addInsString);
  // addTree.InsertOrIncrement(addInsString);
  // addTree.InsertOrIncrement(addInsString);

  // BST<string> sumTree = newTree + addTree;
  // cout << "SUM TREE" << endl;
  // cout << sumTree << endl;




  // BST<int> myIntTree;
  // ifstream inputFile;
  // string fileName = argv[1];

  // inputFile.open(fileName.c_str());
  // while (inputFile.is_open())
  // {
  //   // Take in next int
  //   int nextInt;
  //   inputFile >> nextInt;

  //   if (inputFile.eof())
  //   {
  //     inputFile.close();
  //     continue;
  //   }
  //   int *insInt = new int(nextInt);
  //   myIntTree.InsertOrIncrement(insInt);
  //   delete insInt;
  // }

  // cout << myIntTree << endl;

  return 0;
}
