//
// Created by derrick on 2/14/16.
//

#include "BitStream.h"
#include <math.h>

BitInputStream::BitInputStream(ifstream* in)
{
    inStream = in;
    count = 0;
    buffer = 0;
}

unsigned int BitInputStream::ReadBit()
{
    if (count == 0)
    {
        char symbol = inStream->get();
        buffer = static_cast<unsigned char>(symbol);
        count = 8;
    }

    unsigned int bit = (buffer >> --count) & 1;
    return bit;
    }

BitOutputStream::BitOutputStream(ofstream* out)
{
    outStream = out;
    count = 0;
    buffer = 0;
}

void BitOutputStream::WriteBits(unsigned bits, int numBits)
{
    unsigned mask = pow(2, numBits - 1);
    while (mask != 0)
    {
        buffer = buffer << 1;
        if (mask & bits)
        {
            buffer |= 1;
        }
        mask = mask >> 1;
        count++;
        if (count == 8)
        {
            *outStream << buffer;
            buffer = 0;
            count = 0;
        }
    }
}

void BitOutputStream::WriteBit(unsigned bit)
{
    buffer = (buffer << 1) | (bit & 1);
    count++;
    if (count == 8)
    {
        *outStream << buffer;
        count = 0;
    }
}

int BitOutputStream::Flush()
{
    buffer = buffer << (8 - count);
    (*outStream) << buffer;
    int temp = count;
    count = 0;
    return temp;
}