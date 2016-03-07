/**
 * Filename:    FrequencyTable.cpp
 * Author:      Derrick Maestas
 * Project:     CSS 503 Program 3: The Good Mr. Huffman
 *
 * Description: Implementation of the FrequencyTable class.
 */

#include "FrequencyTable.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Function: FrequencyTable
 * -----------------------------------------------------------------------------
 * No parameter constructor for the FrequencyTable class.
 * This function initializes an empty frequency table.
 */
FrequencyTable::FrequencyTable()
{
    count = 0;
}

/*
/* Function: FrequencyTable
 * -----------------------------------------------------------------------------
 * Constructs a FrequencyTable by reading the header of the specified file
 * (compressed).
 */
FrequencyTable::FrequencyTable(ifstream& in)
{
    in.read(reinterpret_cast<char *>(symbolFrequency), sizeof(symbolFrequency));
    in >> count;
}

/*
 * Function: BuildFrequencyTable
 * -----------------------------------------------f------------------------------
 * Populates a FrequencyTable from input file (uncompressed).
 * Calculates the frequency of each character in the input file and the total
 * number of characters in the file.
 */
void FrequencyTable::BuildFrequencyTable(ifstream& in)
{
    unsigned int symbol;

    while ((symbol = in.get()) != EOF) {
        symbolFrequency[symbol]++;
        count++;
    }
}

/*
 * Function: getCount
 * -----------------------------------------------------------------------------
 * Returns the number of characters in the file associated with the FrequencyTable
 */
unsigned int FrequencyTable::getCount() const
{
    return count;
}

/*
 * Function: getFrequency
 * -----------------------------------------------------------------------------
 * Returns the number of times a character appears in the file associated with
 * the FrequencyTable
 */
unsigned short FrequencyTable::getFrequency(unsigned char symbol) const
{
    return symbolFrequency[symbol];
}

/*
 * Function: Write
 * -----------------------------------------------------------------------------
 * Writes the FrequencyTable, array of frequencies and character count, to the
 * specified output file (compressed). Used to generate a header in the file.
 */
void FrequencyTable::Write(ofstream& out)
{
    out.write(reinterpret_cast<const char *>(symbolFrequency), sizeof(symbolFrequency));
    out << count;
}

/*
 * Function: PrintFrequencyTable
 * -----------------------------------------------------------------------------
 * Prints the frequency table to the console.
 */
void FrequencyTable::PrintFrequencyTable()
{
    for (int i = 0; i < 256; i++)
    {
        if (symbolFrequency[i] != 0)
        {
            cout << setw(3) << i << " " << symbolFrequency[i] << endl;
        }
    }
    cout << count << endl;
}
