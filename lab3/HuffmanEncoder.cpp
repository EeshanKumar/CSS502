#include "HuffmanEncoder.h"

ostream& operator<<(ostream &outStream, const HuffmanEncoder &myHuffEncoder)
{
  for (int i = 0; i < 256; i++)
  {
    if (myHuffEncoder.encodingArray[i].getFrequency() != 0)
    {
      cout << myHuffEncoder.encodingArray[i];
    }
  }
}

HuffmanEncoder::HuffmanEncoder()
{
  initializeEncodingArray();
}

HuffmanEncoder::~HuffmanEncoder()
{
  ClearHuffmanTree();
}

void HuffmanEncoder::initializeEncodingArray()
{
  for (int i = 0; i < 256; i++)
  {
    HuffNode newNode(i, 0, 0, 0);
    encodingArray[i] = newNode;
  }
}

int HuffmanEncoder::getTotalCharCount() const
{
  return totalCharCount;
}

bool HuffmanEncoder::getEncodingFromChar(char charToEncode, unsigned int &bitEncoding, unsigned short &numBits) const
{
  if (encodingArray[charToEncode].getNumBits() == 0)
  {
    return false;
  }
  bitEncoding = encodingArray[charToEncode].getBitEncoding();
  numBits = encodingArray[charToEncode].getNumBits();
  return true;
}

bool HuffmanEncoder::getCharFromEncoding(unsigned int bitEncoding, unsigned short numBits, char &decodedChar) const
{
  // return findEncodedChar(rootTree, bitEncoding, numBits, decodedChar);
  for (int i = 0; i < 256; i++)
  {
    unsigned short charNumBits = encodingArray[i].getNumBits();
    unsigned int charBitEncoding = encodingArray[i].getBitEncoding();
    if ((charNumBits == numBits) && (charBitEncoding == bitEncoding))
    {
      decodedChar = i;
      return true;
    }
  }
  return false;
}


bool HuffmanEncoder::AddChar(char insChar, unsigned int frequency)
{
  int insInt = insChar;
  encodingArray[insInt].IncrementFrequency(frequency);
  totalCharCount += frequency;
  return true;
}
bool HuffmanEncoder::RemoveChar(char insChar, unsigned int frequency)
{
  if (encodingArray[insChar].getFrequency() == 0)
  {
    return false;
  }
  encodingArray[insChar].DecrementFrequency(frequency * -1);
  totalCharCount -= frequency;
  return true;
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
  ClearHuffmanTree();
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
void HuffmanEncoder::ClearHuffmanTree()
{
  clearHuffmanTreeHelper(this->rootTree);
}

void HuffmanEncoder::clearHuffmanTreeHelper(HuffNode* &subTree)
{
  if (subTree == NULL)
  {
    return;
  }
  clearHuffmanTreeHelper(subTree->getLeft());
  clearHuffmanTreeHelper(subTree->getRight());
  delete subTree;
  subTree = NULL;
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
