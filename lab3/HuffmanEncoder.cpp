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

bool HuffmanEncoder::getFreqFromChar(char lookupChar, unsigned int &frequency) const
{
  frequency = encodingArray[lookupChar].getFrequency();
  return true;
}

bool HuffmanEncoder::getEncodingFromChar(char lookupChar, unsigned int &bitEncoding, unsigned short &numBits) const
{
  if (encodingArray[lookupChar].getNumBits() == 0)
  {
    return false;
  }
  bitEncoding = encodingArray[lookupChar].getBitEncoding();
  numBits = encodingArray[lookupChar].getNumBits();
  return true;
}

bool HuffmanEncoder::getCharFromEncoding(unsigned int bitEncoding, unsigned short numBits, char &decodedChar) const
{
  for (int i = 0; i < 256; i++)
  {
    unsigned short charNumBits = encodingArray[i].getNumBits();
    unsigned int charBitEncoding = encodingArray[i].getBitEncoding();
    if ((charNumBits == numBits) && (charBitEncoding == bitEncoding))
    {
      decodedChar = encodingArray[i].getSymbol();
      return true;
    }
  }
  return false;
}

bool HuffmanEncoder::AddChar(char insChar, unsigned int frequency)
{
  encodingArray[insChar].IncrementFrequency(frequency);
  totalCharCount += frequency;
  return true;
}

bool HuffmanEncoder::RemoveChar(char insChar, unsigned int frequency)
{
  if (encodingArray[insChar].getFrequency() == 0)
  {
    return false;
  }
  encodingArray[insChar].DecrementFrequency(frequency);

  if (frequency > totalCharCount)
  {
    totalCharCount = 0;
  }
  else
  {
    totalCharCount -= frequency;
  }
  return true;
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

  while (myPriorityQueue.getCount() >= 2)
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

  this->rootTree = insNode;
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
    char encodedChar = subTree->getSymbol();
    encodingArray[encodedChar] = *subTree;
  }

  HuffNode* left = subTree->getLeft();
  HuffNode* right = subTree->getRight();

  if (left != NULL)
  {
    left->setNumBits(subTree->getNumBits() + 1);
    left->setBitEncoding(subTree->getBitEncoding() * 2);
    setEncodings(subTree->getLeft());
  }
  if (right != NULL)
  {
    right->setNumBits(subTree->getNumBits() + 1);
    right->setBitEncoding((subTree->getBitEncoding() * 2) + 1);
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

void HuffmanEncoder::PrintFrequenciesToOutStream(ostream &outStream) const
{
  for (int i = 0; i < 256; i++)
  {
    outStream << encodingArray[i].getFrequency() << endl;
  }
}

void HuffmanEncoder::PrintHuffmanTree() const
{
  printHuffmanSubTree(this->rootTree);
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
