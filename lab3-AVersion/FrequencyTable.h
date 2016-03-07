/**
 * Filename:    FrequencyTable.h
 * Author:      Derrick Maestas
 * Project:     CSS 503 Program 3: The Good Mr. Huffman
 *
 * Description: Header file of the FrequencyTable class. Definitions of the
 * functions and data used to generate a frequency table of characters in a file.
 */

#ifndef LAB3_FREQUENCYTABLE_H
#define LAB3_FREQUENCYTABLE_H

#include <istream>
#include <ostream>
#include <fstream>

using namespace std;

class FrequencyTable {

public:
    FrequencyTable();
    FrequencyTable(ifstream& in);

    void BuildFrequencyTable(ifstream& in);

    void Write(ofstream& out);
    void Read(ifstream& in);

    unsigned int getCount() const;
    unsigned short getFrequency(unsigned char c) const;

    void PrintFrequencyTable();

private:
    unsigned int   count;                       // total number of characters
    unsigned short symbolFrequency[256]  = {};  // frequency of symbols to encode
};

#endif //LAB3_FREQUENCYTABLE_H
