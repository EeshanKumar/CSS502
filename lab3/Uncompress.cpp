#include <iostream>
#include <fstream>
#include <queue>
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

  inputFile.open(fileName.c_str());
  //Read in frequencies from file
  for (int i = 0; i < 256; i++)
  {
    char nextChar = i;
    int nextFreq;
    inputFile >> nextFreq;
    myEncoding.AddCharWithFrequency(nextChar, nextFreq);
  }

  myEncoding.GenerateHuffmanEncodings();

  queue<bool> encodedBits;
  ofstream outFile;
  string outFileName = (fileName + ".puf").c_str();
  outFile.open(outFileName);

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

  int encodedChar = 0;
  unsigned short numBits = 0;
  char decodingChar;
  int count = 0;

  while ((count < myEncoding.getTotalCount()) && !(encodedBits.empty()))
  {
    bool nextBit = encodedBits.front();
    encodedBits.pop();
    encodedChar = (encodedChar << 1) | nextBit;
    numBits++;

    if (myEncoding.getDecodedChar(encodedChar, numBits, decodingChar))
    {
      //Output encoding to filname.huf
      outFile << decodingChar;
      count++;
      encodedChar = 0;
      numBits = 0;
    }
  }

  return 0;
}
