/**
 * Filename:    HuffmanTree.h
 * Author:      Derrick Maestas
 * Project:     CSS 503 Program 3: The Good Mr. Huffman
 *
 * Description: Header file for the HuffmanTree class
 *
 */

#ifndef LAB3_HUFFMANTREE_H
#define LAB3_HUFFMANTREE_H

#include "FrequencyTable.h"
#include "HuffmanNode.h"
#include "HuffmanPQueue.h"
#include "BitStream.h"

class HuffmanTree
{

public:
    HuffmanTree(const FrequencyTable& frequencies);
    ~HuffmanTree();

    void Encode(ifstream& inFile, ofstream& outFile);
    void Decode(ifstream& inFile, ofstream& outFile, unsigned int numSymbols);

    void PrintEncodingTable();

private:

    struct Encoding
    {
        int bitEncoding;
        unsigned short numBits;
    };

    HuffmanNode* rootPtr;
    Encoding encodingTable[256];

    void clearTree(HuffmanNode *subTreePtr);
    void encodeHelp(HuffmanNode* current, Encoding encoding);
    unsigned char decodeHelp(HuffmanNode* current, BitInputStream& inputBits);
    void writeEncoding(ifstream& inFile, ofstream& outFile);

};


#endif //LAB3_HUFFMANTREE_H
