#include "HuffNode.h"

ostream& operator<<(ostream &outStream, const HuffNode &myHuffNode)
{
  if (myHuffNode.getIsSymbol())
  {
    outStream << "Symbol: " << myHuffNode.getSymbol() << " ";
    outStream << "appearing " << myHuffNode.getFrequency() << " times ";
    outStream << "encoded as " << myHuffNode.getBitEncoding() << " ";
    outStream << "with " << myHuffNode.getNumBits() << " bits" << endl;
    return outStream;
  }
  else
  {
    outStream << "HuffNode with frequency: " << myHuffNode.getFrequency() << endl;
  }
}

HuffNode::HuffNode()
{
}

HuffNode::HuffNode(char symbol)
{
  this->symbol = symbol;
  this->isSymbol = true;
}

HuffNode::HuffNode(char symbol, unsigned int frequency)
{
  this->symbol = symbol;
  this->frequency = frequency;
  this->isSymbol = true;
}

HuffNode::HuffNode(char symbol, unsigned int frequency, unsigned int bitEncoding)
{
  this->symbol = symbol;
  this->frequency = frequency;
  this->bitEncoding = bitEncoding;
  this->isSymbol = true;
}

HuffNode::HuffNode(char symbol, unsigned int frequency, unsigned int bitEncoding, unsigned short numBits)
{
  this->symbol = symbol;
  this->frequency = frequency;
  this->bitEncoding = bitEncoding;
  this->numBits = numBits;
  this->isSymbol = true;
}

HuffNode::HuffNode(unsigned int frequency, bool isSymbol)
{
  this->frequency = frequency;
  this->isSymbol = isSymbol;
}

HuffNode::~HuffNode()
{
}


char HuffNode::getSymbol() const
{
  return symbol;
}
unsigned int HuffNode::getFrequency() const
{
  return frequency;
}
unsigned int HuffNode::getBitEncoding() const
{
  return bitEncoding;
}
unsigned short HuffNode::getNumBits() const
{
  return numBits;
}
bool HuffNode::getIsSymbol() const
{
  return isSymbol;
}
HuffNode*& HuffNode::getLeft()
{
  return left;
}
HuffNode*& HuffNode::getRight()
{
  return right;
}

bool HuffNode::setSymbol(char symbol)
{
  this->symbol = symbol;
  this->isSymbol = true;
  return true;
}
bool HuffNode::setFrequency(unsigned int frequency)
{
  this->frequency = frequency;
  return true;
}
bool HuffNode::setBitEncoding(unsigned int bitEncoding)
{
  this->bitEncoding = bitEncoding;
  this->isSymbol = true;
  return true;
}
bool HuffNode::setNumBits(unsigned short numBits)
{
  this->numBits = numBits;
  this->isSymbol = true;
  return true;
}
bool HuffNode::setIsSymbol(bool isSymbol)
{
  this->isSymbol = isSymbol;
  return true;
}
bool HuffNode::setLeft(HuffNode* &left)
{
  this->left = left;
  return true;
}
bool HuffNode::setRight(HuffNode* &right)
{
  this->right = right;
  return true;
}

bool HuffNode::IncrementFrequency(unsigned int amount)
{
  frequency += amount;
  return true;
}
bool HuffNode::DecrementFrequency(unsigned int amount)
{
  if (amount > frequency)
  {
    frequency = 0;
  }
  else
  {
    frequency -= amount;
  }
  return true;
}

bool HuffNode::operator<(const HuffNode &rhs) const
{
  return (frequency < rhs.frequency);
}

bool HuffNode::operator<=(const HuffNode &rhs) const
{
  if (*this == rhs)
  {
    return true;
  }
  return (*this < rhs);
}
bool HuffNode::operator>(const HuffNode &rhs) const
{
  return (frequency > rhs.frequency);
}

bool HuffNode::operator>=(const HuffNode &rhs) const
{
  if (*this == rhs)
  {
    return true;
  }
  return (*this > rhs);
}

bool HuffNode::operator==(const HuffNode &rhs) const
{
  return ((symbol == rhs.symbol) && (frequency == rhs.frequency));
}

bool HuffNode::operator!=(const HuffNode &rhs) const
{
  return ((symbol != rhs.symbol) || (frequency != rhs.frequency));
}
