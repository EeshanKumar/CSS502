#include "BitWriter.h"

BitWriter::BitWriter()
{
}
BitWriter::BitWriter(ostream *outStream)
{
  this->outStream = outStream;
}
BitWriter::~BitWriter()
{
}

int BitWriter::getCount() const
{
  return count;
}

void BitWriter::setStream(ostream *outStream)
{
  this->outStream = outStream;
}

void BitWriter::WriteBit(unsigned bit)
{
  buf = (buf << 1) | (bit & 1);
  count++;
  if (count == 8)
  {
    *outStream << buf;
    count = 0;
  }
}

void BitWriter::WriteBits(unsigned bits, int numBits)
{
  unsigned mask = pow(2, numBits - 1);
  while (mask != 0)
  {
    buf = buf << 1;
    if (mask & bits)
    {
      buf |= 1;
    }
    mask = mask >> 1;
    count++;
    if (count == 8)
    {
      *outStream << buf;
      count = 0;
    }
  }
}

int BitWriter::Flush()
{
  buf = buf << (8 - count);
  *outStream << buf;
  int temp = count;
  count = 0;
  return temp;
}
