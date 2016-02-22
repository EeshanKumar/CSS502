#include <iostream>
#include <fstream>
using namespace std;
#include "HuffmanEncoder.h"
#include "BitWriter.h"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    cout << "Please input a filename as an argument" << endl;
    return 0;
  }

  HuffmanEncoder myEncoding;
  ifstream inputFile;
  string fileName = argv[1];

  //Read in characters from file
  inputFile.open(fileName.c_str(), ios::in | ios::binary);
  while (inputFile.is_open())
  {
    char nextChar;
    inputFile >> noskipws >> nextChar;

    if (inputFile.eof())
    {
      inputFile.close();
      continue;
    }
    myEncoding.AddChar(nextChar, 1);
  }

  myEncoding.GenerateHuffmanEncodings();

  ofstream outFile;
  string outFileName = (fileName + ".huf").c_str();
  outFile.open(outFileName, ios::out | ios::binary | ios::trunc);
  BitWriter myBitWriter(&outFile);

  myEncoding.PrintFrequenciesToOutStream(outFile);

  //Read in characters from file and encode
  inputFile.open(fileName.c_str());
  while (inputFile.is_open())
  {
    // Take in next string
    char nextChar;
    unsigned int bitEncoding;
    unsigned short numBits;

    inputFile >> noskipws >> nextChar;

    if (inputFile.eof())
    {
      inputFile.close();
      continue;
    }
    if (myEncoding.getEncodingFromChar(nextChar, bitEncoding, numBits))
    {
      //Output encoding to filname.huf
      myBitWriter.WriteBits(bitEncoding, numBits);
    }
    else
    {
      cerr << "Error! Encoded character not found! Skipping..." << endl;
    }
  }
  myBitWriter.Flush();

  return 0;
}
