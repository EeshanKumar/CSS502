/**
 * Filename:    HuffmanPQueue.cpp
 * Author:      Derrick Maestas
 * Project:     CSS 503 Program 3: The Good Mr. Huffman
 *
 * Description: Implementation of the HuffmanPQueue class
 *
 */

#include <iostream>
#include "HuffmanPQueue.h"

/**
 * Function: HuffmanPQueue
 * -----------------------------------------------------------------------------
 * No argument constructor for class HuffmanPQueue
 */
HuffmanPQueue::HuffmanPQueue()
{
}


/**
 * Function: ~HuffmanPQueue
 * -----------------------------------------------------------------------------
 * Destructor for class HuffmanPQueue
 */
HuffmanPQueue::~HuffmanPQueue()
{
}

/**
 * Function: isEmpty
 * -----------------------------------------------------------------------------
 * Returns the number of elements in the priority queue.
 */
bool HuffmanPQueue::isEmpty()
{
    return heap.empty();
}

/**
 * Function: isEmpty
 * -----------------------------------------------------------------------------
 * Returns the size of the priority queue.
 */
int HuffmanPQueue::size()
{
    return (int) heap.size() - 1;
}

/**
 * Function: Enqueue
 * -----------------------------------------------------------------------------
 * No argument constructor for class HuffmanPQueue
 */
void HuffmanPQueue::Enqueue(HuffmanNode* tree)
{
    if (isEmpty())
    {
        heap.push_back(tree);
    }
    else
    {
        heap[0] = tree;
    }

    heap.push_back(tree);

    count++;
    int position = count;

    while (heap[position/2]->getWeight() > tree->getWeight())
    {
        swap(heap[position], heap[position / 2]);
        position = position / 2;
    }
}

/**
 * Function: DequeueMin
 * -----------------------------------------------------------------------------
 * Dequeues the first value in the priority queue
 */
HuffmanNode* HuffmanPQueue::DequeueMin()
{
    if (isEmpty() || count == 0) {
        cout << "Cannot dequeue from an empty priority queue.";
        return nullptr;
    }

    HuffmanNode* retVal = heap[1];
    heap[1] = heap[count];
    heap.pop_back();
    count--;
    percolateDown(1);
    return retVal;
}

/**
 * Function: percolateDown
 * -----------------------------------------------------------------------------
 * Moves the value at the specified position to the correct location in the
 * priority queue.
 */
void HuffmanPQueue::percolateDown(int position)
{
    int child = 2 * position;

    if (child > count)
    {
        return;
    }

    if ((count != child) && (heap[child]->getWeight() > heap[child + 1]->getWeight()))
    {
        child++;
    }

    if (heap[position]->getWeight() > heap[child]->getWeight() )
    {
        swap(heap[position], heap[child]);
        percolateDown(child);
    }
}

/**
 * Function: PrintPQueue
 * -----------------------------------------------------------------------------
 * Prints a representation of the priority queue to the console.
 */
void HuffmanPQueue::PrintPQueue()
{
    for (int i = 1; i < heap.size() ; ++i)
    {
        cout << (int) heap[i]->getSymbol() << " " << heap[i]->getWeight() << endl;
    }

}
