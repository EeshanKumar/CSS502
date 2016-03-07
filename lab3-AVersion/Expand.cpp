/**
 * Filename:    Expand.cpp
 * Author:      Derrick Maestas
 * Project:     CSS 503 Program 3: The Good Mr. Huffman
 *
 * Description: Driver program to expand the specified, previously compressed
 * file.
 */

#include "FrequencyTable.h"
#include "HuffmanTree.h"

using namespace std;


int main(int argc, char* argv[])
{
    const string inFile = argv[1];
    string outFile = inFile + ".puf";

    ifstream inStream(inFile, ios::binary);
    ofstream outStream(outFile);

    FrequencyTable frequencyTable(inStream);
    HuffmanTree huffTree(frequencyTable);
    huffTree.Decode(inStream, outStream, frequencyTable.getCount());

    return 0;
}