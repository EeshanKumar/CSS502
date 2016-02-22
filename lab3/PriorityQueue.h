#include <iostream>
#include <vector>
using namespace std;

template <class ItemType>
class PriorityQueue
{
  template <class T>
  friend ostream& operator<<(ostream &outStream, PriorityQueue<T> &myPriorityQueue);

public:
//Constructors & Destructors
  PriorityQueue();
  ~PriorityQueue();

//Getters
  int getCount() const;

//Public Functions
  void Add(const ItemType &item);
  bool Peek(ItemType &item);
  bool Remove(ItemType &item);

private:
  vector<ItemType> minHeap;
  int count = 0;

  void percolateDown(int position);
  void swap(ItemType &item1, ItemType &item2);
};

//Becasue this is a templated class, the implementation is sub optimally in the .h file

template <class T>
ostream& operator<<(ostream &outStream, PriorityQueue<T> &myPriorityQueue)
{
  int size = myPriorityQueue.getCount();
  for (int i = 1; i <= size; i++)
  {
    outStream << myPriorityQueue.minHeap[i];
  }
  return outStream;
}

template <class ItemType>
PriorityQueue<ItemType>::PriorityQueue()
{
  ItemType blank;
  minHeap.push_back(blank);
}

template <class ItemType>
PriorityQueue<ItemType>::~PriorityQueue()
{
}

template <class ItemType>
int PriorityQueue<ItemType>::getCount() const
{
  return count;
}

template <class ItemType>
void PriorityQueue<ItemType>::Add(const ItemType &item)
{
  minHeap[0] = item;

  minHeap.push_back(item);
  count++;
  int position = count;

  while (minHeap[position / 2] > item)
  {
    swap(minHeap[position / 2], minHeap[position]);
    position = position / 2;
  }
}

template <class ItemType>
bool PriorityQueue<ItemType>::Peek(ItemType &item)
{
  if (count > 0)
  {
    item = minHeap[1];
    return true;
  }
  return false;
}

template <class ItemType>
bool PriorityQueue<ItemType>::Remove(ItemType &item)
{
  if (count == 0)
  {
    return false;
  }
  item = minHeap[1];
  minHeap[1] = minHeap[count];
  minHeap.pop_back();
  count--;
  if (count > 0)
  {
    percolateDown(1);
  }
  return true;
}

template <class ItemType>
void PriorityQueue<ItemType>::percolateDown(int position)
{
  int child = position * 2;
  if (child > count)
  {
    return;
  }
  if ((child != count) && (minHeap[child + 1] < minHeap[child]))
  {
    child++;
  }
  if (minHeap[child] < minHeap[position])
  {
    swap(minHeap[child], minHeap[position]);
    percolateDown(child);
  }
}

template <class ItemType>
void PriorityQueue<ItemType>::swap(ItemType &item1, ItemType &item2)
{
  ItemType temp = item1;
  item1 = item2;
  item2 = temp;
}
