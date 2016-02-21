#include <iostream>
using namespace std;
#include "PriorityQueue.h"
#include "HuffNode.h"

class HuffmanEncoder
{
public:

//Constructors + Destructors
  HuffmanEncoder();
  ~HuffmanEncoder();

//Public Functions
  bool AddChar(char insChar);
  bool RemoveChar(char delChar);
  bool AddCharWithFrequency(char insChar, int frequency);
  bool RemoveCharWithFrequency(char insChar, int frequency);

  int getTotalCount() const;

  void Print() const;
  void PrintHuffmanTree() const;
  void PrintFrequenciesToOutStream(ostream &outStream) const;

  bool GenerateHuffmanEncodings();
  bool GenerateHuffmanTree();
  void ClearHuffmanTree(HuffNode* &subTree);

  bool getEncoding(char charToEncode, unsigned int &bitEncoding, unsigned short &numBits) const;
  bool getDecodedChar(int encodedChar, unsigned short numBits, char &decodedChar) const;


private:
  unsigned int totalCount = 0;
  HuffNode encodingArray[256];
  HuffNode* rootTree = NULL;

  bool findEncodedChar(HuffNode* subTree, int encodedChar, unsigned short numBits, char &decodedChar) const;
  void setEncodings(HuffNode* subTree);
  void printHuffmanSubTree(HuffNode* subTree) const;
  void initializeEncodingArray();
};

void HuffmanEncoder::initializeEncodingArray()
{
  for (int i = 0; i < 256; i++)
  {
    HuffNode newNode(i, 0, 0, 0);
    encodingArray[i] = newNode;
  }
}


HuffmanEncoder::HuffmanEncoder()
{
  initializeEncodingArray();
}

HuffmanEncoder::~HuffmanEncoder()
{
  ClearHuffmanTree(this->rootTree);
}


bool HuffmanEncoder::AddChar(char insChar)
{
  encodingArray[insChar].IncrementFrequency(1);
  totalCount++;
  return true;
}
bool HuffmanEncoder::RemoveChar(char insChar)
{
  if (encodingArray[insChar].getFrequency() == 0)
  {
    return false;
  }
  encodingArray[insChar].DecrementFrequency(-1);
  totalCount--;
  return true;
}
bool HuffmanEncoder::AddCharWithFrequency(char insChar, int frequency)
{
  int insInt = insChar;
  encodingArray[insInt].IncrementFrequency(frequency);
  totalCount += frequency;
  return true;
}
bool HuffmanEncoder::RemoveCharWithFrequency(char insChar, int frequency)
{
  if (encodingArray[insChar].getFrequency() == 0)
  {
    return false;
  }
  encodingArray[insChar].DecrementFrequency(frequency * -1);
  totalCount -= frequency;
  return true;
}

int HuffmanEncoder::getTotalCount() const
{
  return totalCount;
}

bool HuffmanEncoder::getEncoding(char charToEncode, unsigned int &bitEncoding, unsigned short &numBits) const
{
  if (encodingArray[charToEncode].getNumBits() == 0)
  {
    return false;
  }
  bitEncoding = encodingArray[charToEncode].getBitEncoding();
  numBits = encodingArray[charToEncode].getNumBits();
  return true;
}

bool HuffmanEncoder::getDecodedChar(int encodedChar, unsigned short numBits, char &decodedChar) const
{
  // return findEncodedChar(rootTree, encodedChar, numBits, decodedChar);
  for (int i = 0; i < 256; i++)
  {
    unsigned short charNumBits = encodingArray[i].getNumBits();
    int charBitEncoding = encodingArray[i].getBitEncoding();
    if ((charNumBits == numBits) && (charBitEncoding == encodedChar))
    {
      decodedChar = i;
      return true;
    }
  }
  return false;
}

// UNFISHED! Partial credit maybe?
bool HuffmanEncoder::findEncodedChar(HuffNode* subTree, int encodedChar, unsigned short numBits, char &decodedChar) const
{
  int buf = encodedChar;
  cout << "buf before " << buf << endl;
  buf = buf;
  cout << "buf after " << buf << endl;
  return true;
  if (buf == 0)
  {
    HuffNode* nextTree = subTree->getLeft();
    if (nextTree == NULL)
    {
      return false;
    }
    if (nextTree->getIsSymbol() && (nextTree->getNumBits() == numBits)) {
      decodedChar = nextTree->getSymbol();
      return true;
    }
    else
    {
      return findEncodedChar(subTree->getLeft(), encodedChar << 1, numBits, decodedChar);
    }
  }
  else
  {
    HuffNode* nextTree = subTree->getRight();
    if (nextTree == NULL)
    {
      return false;
    }
    if (nextTree->getIsSymbol() && (nextTree->getNumBits() == numBits)) {
      decodedChar = nextTree->getSymbol();
      return true;
    }
    else
    {
      return findEncodedChar(subTree->getRight(), encodedChar << 1, numBits, decodedChar);
    }
  }
}


bool HuffmanEncoder::GenerateHuffmanEncodings()
{
  GenerateHuffmanTree();
  setEncodings(this->rootTree);
  ClearHuffmanTree(this->rootTree);
}
bool HuffmanEncoder::GenerateHuffmanTree()
{
  PriorityQueue<HuffNode> myPriorityQueue;

  //Create priority queue
  for (int i = 0; i < 256; i++)
  {
    if (encodingArray[i].getFrequency() != 0)
    {
      myPriorityQueue.Add(encodingArray[i]);
    }
  }

  while (myPriorityQueue.getCount() > 1)
  {
    HuffNode huff1;
    HuffNode huff2;
    HuffNode* leftIns;
    HuffNode* rightIns;
    HuffNode combinedHuff;
    myPriorityQueue.Remove(huff1);
    leftIns = new HuffNode(huff1);
    myPriorityQueue.Remove(huff2);
    rightIns = new HuffNode(huff2);

    combinedHuff.setFrequency(huff1.getFrequency() + huff2.getFrequency());
    combinedHuff.setIsSymbol(false);
    combinedHuff.setLeft(leftIns);
    combinedHuff.setRight(rightIns);

    myPriorityQueue.Add(combinedHuff);
  }

  HuffNode rootHuffNode;
  HuffNode* insNode;

  myPriorityQueue.Remove(rootHuffNode);
  insNode = new HuffNode(rootHuffNode);

  rootTree = insNode;
  return true;
}
void HuffmanEncoder::setEncodings(HuffNode* subTree)
{
  if (subTree == NULL)
  {
    return;
  }
  if (subTree->getIsSymbol())
  {
    encodingArray[subTree->getSymbol()] = *subTree;
  }

  if (subTree->getLeft() != NULL)
  {
    (subTree->getLeft())->setNumBits(subTree->getNumBits() + 1);
    (subTree->getLeft())->setBitEncoding(subTree->getBitEncoding() * 2);
    setEncodings(subTree->getLeft());
  }
  if (subTree->getRight() != NULL)
  {
    (subTree->getRight())->setNumBits(subTree->getNumBits() + 1);
    (subTree->getRight())->setBitEncoding((subTree->getBitEncoding() * 2) + 1);
    setEncodings(subTree->getRight());
  }
}
void HuffmanEncoder::ClearHuffmanTree(HuffNode* &subTree)
{
  if (subTree == NULL)
  {
    return;
  }
  ClearHuffmanTree(subTree->getLeft());
  ClearHuffmanTree(subTree->getRight());
  delete subTree;
  subTree = NULL;
}

void HuffmanEncoder::Print() const
{
  for (int i = 0; i < 256; i++)
  {
    if (encodingArray[i].getFrequency() != 0)
    {
      cout << encodingArray[i];
    }
  }
}

void HuffmanEncoder::PrintHuffmanTree() const
{
  printHuffmanSubTree(rootTree);
}

void HuffmanEncoder::printHuffmanSubTree(HuffNode* subTree) const
{
  if (subTree == NULL)
  {
    return;
  }
  HuffNode* left = subTree->getLeft();
  HuffNode* right = subTree->getRight();
  printHuffmanSubTree(left);
  cout << *subTree;
  printHuffmanSubTree(right);
}

void HuffmanEncoder::PrintFrequenciesToOutStream(ostream &outStream) const
{
  for (int i = 0; i < 256; i++)
  {
    outStream << encodingArray[i].getFrequency() << endl;
  }
}
