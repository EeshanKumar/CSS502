//
// Created by derrick on 2/14/16.
//

#ifndef LAB3_BITSTREAM_H
#define LAB3_BITSTREAM_H

#include <fstream>
#include <iostream>
#include <bitset>

using namespace std;

class BitInputStream
{
public:
    BitInputStream(ifstream* in);
    unsigned int ReadBit();

private:
    ifstream* inStream;
    int count;
    unsigned char buffer;
};

class BitOutputStream
{
public:
    BitOutputStream(ofstream* out);
    void WriteBits(unsigned bits, int numBits);
    void WriteBit(unsigned bit);

    int Flush();

private:
    ofstream* outStream;
    int count;
    unsigned char buffer;
};

#endif //LAB3_BITSTREAM_H
