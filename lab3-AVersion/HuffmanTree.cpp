/**
 * Filename:    HuffmanTree.cpp
 * Author:      Derrick Maestas
 * Project:     CSS 503 Program 3: The Good Mr. Huffman
 *
 * Description: Implementation of the HuffmanTree class
 */
#include <iostream>
#include <iomanip>
#include "HuffmanTree.h"

/*
 * Function: HuffmanTree
 * -----------------------------------------------------------------------------
 * Constructor for a huffman tree based on the specified frequency table
 */
HuffmanTree::HuffmanTree(const FrequencyTable& frequencies)
{
    HuffmanPQueue pQueue;

    // generate a leaf node for each symbol
    for (int i = 0; i < 256; ++i)
    {
        if(frequencies.getFrequency(i) != 0)
        {
            HuffmanNode* leafNode = new HuffmanNode(i, frequencies.getFrequency(i));
            pQueue.Enqueue(leafNode);
        }
    }

    while (pQueue.size() > 1) {
        HuffmanNode* left = pQueue.DequeueMin();
        HuffmanNode* right = pQueue.DequeueMin();
        HuffmanNode* parent = new HuffmanNode(left, right);
        pQueue.Enqueue(parent);
    }

    rootPtr = pQueue.DequeueMin();
}

/*
 * Function: ~HuffmanTree
 * -----------------------------------------------------------------------------
 * Destructor for the HuffmanTree class
 */
HuffmanTree::~HuffmanTree()
{
    clearTree(rootPtr);
    rootPtr = nullptr;
}

/**
 * Function: clearTree
 * -----------------------------------------------------------------------------
 *  Recursively deletes all nodes and data from the tree.
 */
void HuffmanTree::clearTree(HuffmanNode *subTreePtr)
{
    // If root node of subtree is null (base case), target is not in tree
    if (subTreePtr == nullptr)
    {
        return;
    }

    // remove left and right subtrees
    if (subTreePtr->leftPtr != nullptr)
    {
        clearTree(subTreePtr->leftPtr);
    }

    if (subTreePtr->rightPtr != nullptr)
    {
        clearTree(subTreePtr->rightPtr);
    }

    delete subTreePtr;
    subTreePtr == nullptr;
}

/*
 * Function: Encode
 * -----------------------------------------------------------------------------
 * Determines the encoding for every character in the input file, and writes the
 * encoded data to the output (compressed) file.
 */
void HuffmanTree::Encode(ifstream& inFile, ofstream& outFile)
{
    Encoding encoding;
    encoding.bitEncoding = 0;
    encoding.numBits = 0;

    for (int i = 0 ; i < 256; ++i) {
        encodingTable[i] = encoding;
    }

    encodeHelp(rootPtr, encoding);
    writeEncoding(inFile, outFile);
}

/*
 * Function: encodeHelp
 * -----------------------------------------------------------------------------
 * Recursively moves down the huffman tree until the encoding for every character
 * in the tree is determined
 */
void HuffmanTree::encodeHelp(HuffmanNode* current, Encoding encoding)
{
    if (current->isLeaf())
    {
        encodingTable[current->symbol].bitEncoding = encoding.bitEncoding;
        encodingTable[current->symbol].numBits = encoding.numBits;
    }
    else
    {
        encoding.numBits++;

        // append a zero to the encoding
        Encoding leftEncoding;
        leftEncoding.bitEncoding = encoding.bitEncoding <<  1;
        leftEncoding.numBits = encoding.numBits;
        encodeHelp(current->leftPtr, leftEncoding);

        // append a one to the encoding
        Encoding rightEncoding;
        rightEncoding.bitEncoding = encoding.bitEncoding <<  1 | 1;
        rightEncoding.numBits = encoding.numBits;
        encodeHelp(current->rightPtr, rightEncoding);
    }
}

/**
 * Function: writeEncoding
 * -----------------------------------------------------------------------------
 * Reads the uncompressed input file and writes the encoded version to the specified
 * output file (compressed).
 */
void HuffmanTree::writeEncoding(ifstream& inFile, ofstream& outFile)
{
    inFile.clear();
    inFile.seekg(0);
    BitOutputStream outputBits(&outFile);

    int symbol;
    while ((symbol = inFile.get()) != EOF)
    {
        outputBits.WriteBits(encodingTable[symbol].bitEncoding,
                             encodingTable[symbol].numBits);
    }

    outputBits.Flush();
}

/*
 * Function: Decode
 * -----------------------------------------------------------------------------
 * Decodes the specified file that has previously been encoded, and writes the
 * decoded data to the specified output file.
 */
void HuffmanTree::Decode(ifstream& in, ofstream& out, unsigned int numSymbols)
{
    BitInputStream inputBits(&in);

    for (int i = 0; i < numSymbols; ++i)
    {
        unsigned char symbol;
        symbol = decodeHelp(rootPtr, inputBits);
        out.put(symbol);
    }
}

/*
 * Function: decodeHelp
 * -----------------------------------------------------------------------------
 * Reads the specified input file and recursively traverses the tree associated
 * with it until a leaf node containing a character is reached.
 */
unsigned char HuffmanTree::decodeHelp(HuffmanNode* current, BitInputStream& inputBits)
{

    if (current->isLeaf())
    {
         return current->getSymbol();
    }

    unsigned int bit = inputBits.ReadBit();
    if (bit)
    {
        decodeHelp(current->rightPtr, inputBits);
    }
    else
    {
        decodeHelp(current->leftPtr, inputBits);
    }
}

/*
 * Function: PrintEncodingTable
 * -----------------------------------------------------------------------------
 * Prints the encoding table to the console.
 */
void HuffmanTree::PrintEncodingTable()
{
    for (int symbol = 0; symbol < 256; ++symbol) {
        if (encodingTable[symbol].numBits > 0) {

            if (isprint(symbol))
            {
                cout << " " << char (symbol) << " (" << symbol << "): [";
            }
            else
            {
                cout << "   (" << symbol << "): [";
            }

            // print encoding
            for (int i = encodingTable[symbol].numBits - 1; i >= 0; --i)
            {
                cout << ((encodingTable[symbol].bitEncoding & (1 << i)) ? "1" : "0");
            }
            cout << "] ";

            cout << (encodingTable[symbol].numBits) << endl;
        }
    }
}



