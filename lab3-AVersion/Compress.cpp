/**
 * Filename:    Compress.cpp
 * Author:      Derrick Maestas
 * Project:     CSS 503 Program 3: The Good Mr. Huffman
 *
 * Description: Driver program to compress the specified file.
 */

#include <fstream>
#include <iostream>

#include "FrequencyTable.h"
#include "HuffmanTree.h"

using namespace std;


int main(int argc, char* argv[]) {
    const string inFile = argv[1];
    string outFile = inFile + ".huf";

    ifstream inStream(inFile, ios::binary);
    ofstream outStream(outFile, ios::binary);

    FrequencyTable frequencyTable;
    frequencyTable.BuildFrequencyTable(inStream);

    //Write  output header
    frequencyTable.Write(outStream);

    //build tree and encoding
    HuffmanTree huffTree(frequencyTable);
    huffTree.Encode(inStream, outStream);

    return 0;
}