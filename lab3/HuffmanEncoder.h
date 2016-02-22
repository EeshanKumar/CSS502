#pragma once
#include <iostream>
using namespace std;
#include "PriorityQueue.h"
#include "HuffNode.h"

class HuffmanEncoder
{
  friend ostream& operator<<(ostream &outStream, const HuffmanEncoder &myHuffEncoder);

public:
//Constructors & Destructors
  HuffmanEncoder();
  ~HuffmanEncoder();

//Getters
  int getTotalCharCount() const;

  bool getFreqFromChar(char lookupChar, unsigned int &frequency) const;
  bool getEncodingFromChar(char lookupChar, unsigned int &bitEncoding, unsigned short &numBits) const;
  bool getCharFromEncoding(unsigned int lookupBitEncoding, unsigned short numBits, char &decodedChar) const;

//Public Functions
  bool AddChar(char insChar, unsigned int frequency);
  bool RemoveChar(char insChar, unsigned int frequency);

  bool GenerateHuffmanEncodings();
  bool GenerateHuffmanTree();
  void ClearHuffmanTree();

  void PrintFrequenciesToOutStream(ostream &outStream) const;
  void PrintHuffmanTree() const;

private:
  unsigned int totalCharCount = 0;
  HuffNode encodingArray[256];
  HuffNode* rootTree = NULL;

  void initializeEncodingArray();
  void setEncodings(HuffNode* subTree);
  void clearHuffmanTreeHelper(HuffNode* &subTree);
  void printHuffmanSubTree(HuffNode* subTree) const;
};
