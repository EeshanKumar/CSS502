class HuffNode
{
  friend ostream& operator<<(ostream &outStream, const HuffNode &myHuffNode);

public:
  HuffNode();
  HuffNode(char symbol);
  HuffNode(char symbol, int frequency);
  HuffNode(char symbol, int frequency, int bitEncoding);
  HuffNode(char symbol, int frequency, int bitEncoding, unsigned short numBits);
  HuffNode(int frequency, bool isSymbol);
  ~HuffNode();

  char getSymbol() const;
  int getFrequency() const;
  int getBitEncoding() const;
  unsigned short getNumBits() const;
  bool getIsSymbol() const;

  HuffNode* &getLeft();
  HuffNode* &getRight();

  bool setSymbol(char symbol);
  bool setFrequency(int frequency);
  bool setBitEncoding(int bitEncoding);
  bool setNumBits(unsigned short numBits);
  bool setIsSymbol(bool isSymbol);
  bool setLeft(HuffNode* &left);
  bool setRight(HuffNode* &right);

  bool IncrementFrequency(int amount);
  bool DecrementFrequency(int amount);

  bool operator<(const HuffNode &rhs) const;
  bool operator<=(const HuffNode &rhs) const;
  bool operator>(const HuffNode &rhs) const;
  bool operator>=(const HuffNode &rhs) const;
  bool operator==(const HuffNode &rhs) const;
  bool operator!=(const HuffNode &rhs) const;

private:
  char symbol;
  int frequency = 0;
  int bitEncoding = 0;
  unsigned short numBits = 0;
  bool isSymbol = true;
  HuffNode* left = NULL;
  HuffNode* right = NULL;
};

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

HuffNode::HuffNode(char symbol, int frequency)
{
  this->symbol = symbol;
  this->frequency = frequency;
  this->isSymbol = true;
}

HuffNode::HuffNode(char symbol, int frequency, int bitEncoding)
{
  this->symbol = symbol;
  this->frequency = frequency;
  this->bitEncoding = bitEncoding;
  this->isSymbol = true;
}

HuffNode::HuffNode(char symbol, int frequency, int bitEncoding, unsigned short numBits)
{
  this->symbol = symbol;
  this->frequency = frequency;
  this->bitEncoding = bitEncoding;
  this->numBits = numBits;
  this->isSymbol = true;
}

HuffNode::HuffNode(int frequency, bool isSymbol)
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
int HuffNode::getFrequency() const
{
  return frequency;
}
int HuffNode::getBitEncoding() const
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
bool HuffNode::setFrequency(int frequency)
{
  this->frequency = frequency;
  return true;
}
bool HuffNode::setBitEncoding(int bitEncoding)
{
  this->bitEncoding = bitEncoding;
  return true;
}
bool HuffNode::setNumBits(unsigned short numBits)
{
  this->numBits = numBits;
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

bool HuffNode::IncrementFrequency(int amount)
{
  frequency += amount;
  return true;
}
bool HuffNode::DecrementFrequency(int amount)
{
  frequency -= amount;
  if (frequency < 0)
  {
    frequency = 0;
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
  return !((symbol == rhs.symbol) && (frequency == rhs.frequency));
}
