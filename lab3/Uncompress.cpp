#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
#include "HuffmanEncoder.h"

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

  inputFile.open(fileName.c_str(), ios::in | ios::binary);
  //Read in frequencies from file
  for (int i = 0; i < 256; i++)
  {
    char nextChar = i;
    unsigned int nextFreq;
    inputFile >> nextFreq;
    myEncoding.AddChar(nextChar, nextFreq);
  }

  myEncoding.GenerateHuffmanEncodings();

  queue<bool> encodedBits;
  ofstream outFile;
  string outFileName = (fileName + ".puf").c_str();
  outFile.open(outFileName, ios::out | ios::binary | ios::trunc);

  //Read in characters from file and queue
  while (inputFile.is_open())
  {
    // Take in next string
    unsigned char nextChar;

    inputFile >> nextChar;

    if (inputFile.eof())
    {
      inputFile.close();
      continue;
    }
    for (int i = 7; i >= 0; i--)
    {
      encodedBits.push(((nextChar >> i) & 1));
    }
  }

  unsigned int bitEncoding = 0;
  unsigned short numBits = 0;
  char decodedChar;
  int count = 0;

  while ((count < myEncoding.getTotalCharCount()) && !(encodedBits.empty()))
  {
    bool nextBit = encodedBits.front();
    encodedBits.pop();
    bitEncoding = (bitEncoding << 1) | nextBit;
    numBits++;

    if (myEncoding.getCharFromEncoding(bitEncoding, numBits, decodedChar))
    {
      //Output encoding to filname.huf
      outFile << decodedChar;
      count++;
      bitEncoding = 0;
      numBits = 0;
    }
  }

  return 0;
}
