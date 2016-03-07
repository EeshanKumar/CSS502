/**
 * Filename:    HuffmanPQueue.cpp
 * Author:      Derrick Maestas
 * Project:     CSS 503 Program 3: The Good Mr. Huffman
 *
 * Description: A priority queue of HuffmanNodes implemented using a min heap.
 *
 */

#ifndef LAB3_HUFFMANPQUEUE_H
#define LAB3_HUFFMANPQUEUE_H

#include <vector>
#include "HuffmanNode.h"

using namespace std;

// Forward declaration for HuffmanNode class
class HuffmanNode;

class HuffmanPQueue {
public:
    HuffmanPQueue();
    ~HuffmanPQueue();

    bool isEmpty();
    int size();

    void Enqueue(HuffmanNode* tree);
    HuffmanNode* DequeueMin();
    void PrintPQueue();

private:
    vector<HuffmanNode*> heap;
    int count = 0;

    void percolateDown(int pos);
};


#endif //LAB3_HUFFMANPQUEUE_H
