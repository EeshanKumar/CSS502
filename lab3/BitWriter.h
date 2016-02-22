#include <cmath>
#include <iostream>
using namespace std;

class BitWriter
{
public:
  BitWriter();
  BitWriter(ostream *outStream);
  ~BitWriter();

  int getCount() const;
  void setStream(ostream *outStream);
  void WriteBit(unsigned bit);
  void WriteBits(unsigned bits, int numBits);
  int Flush();

private:
  ostream *outStream;
  int count = 0;
  unsigned char buf;
};
