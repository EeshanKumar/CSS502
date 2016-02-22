#pragma once
#include <iostream>
using namespace std;

class HuffNode
{
  friend ostream& operator<<(ostream &outStream, const HuffNode &myHuffNode);

public:
//Constructors & Destructors
  HuffNode();
  HuffNode(char symbol);
  HuffNode(char symbol, unsigned int frequency);
  HuffNode(char symbol, unsigned int frequency, unsigned int bitEncoding);
  HuffNode(char symbol, unsigned int frequency, unsigned int bitEncoding, unsigned short numBits);
  HuffNode(unsigned int frequency, bool isSymbol);
  ~HuffNode();

//Getters
  char getSymbol() const;
  unsigned int getFrequency() const;
  unsigned int getBitEncoding() const;
  unsigned short getNumBits() const;
  bool getIsSymbol() const;
  HuffNode* &getLeft();
  HuffNode* &getRight();

//Setters
  bool setSymbol(char symbol);
  bool setFrequency(unsigned int frequency);
  bool setBitEncoding(unsigned int bitEncoding);
  bool setNumBits(unsigned short numBits);
  bool setIsSymbol(bool isSymbol);
  bool setLeft(HuffNode* &left);
  bool setRight(HuffNode* &right);

//Public Functions
  bool IncrementFrequency(unsigned int amount);
  bool DecrementFrequency(unsigned int amount);

//Operator Overloads
  bool operator<(const HuffNode &rhs) const;
  bool operator<=(const HuffNode &rhs) const;
  bool operator>(const HuffNode &rhs) const;
  bool operator>=(const HuffNode &rhs) const;
  bool operator==(const HuffNode &rhs) const;
  bool operator!=(const HuffNode &rhs) const;

private:
  char symbol;
  unsigned int frequency = 0;
  unsigned int bitEncoding = 0;
  unsigned short numBits = 0;
  bool isSymbol = true;
  HuffNode* left = NULL;
  HuffNode* right = NULL;
};
