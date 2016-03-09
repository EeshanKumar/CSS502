#include <cstring>
#include <string>
using namespace std;

const int HASH_SIZE = 211;

template <class ItemType>
class Hash
{
public:

  template <class T>
  friend ostream& operator<<(ostream &outStream, const Hash<T> &hashToPrint);

  Hash();
  ~Hash();

  ItemType* getItem(string key) const;
  bool setItem(string key, ItemType* insItem);

  void Clear();

private:
  struct Node
  {
    string key;
    ItemType* item;
    Node* next;
  };
  Node* hashMap[HASH_SIZE];

  int stringToHashValue(string key);
  void print(ostream &outStream) const;
};


template <class T>
ostream& operator<<(ostream &outStream, const Hash<T> &hashToPrint)
{
  hashToPrint.print(outStream);
  return outStream;
}

template <class ItemType>
void Hash<ItemType>::print(ostream &outStream) const
{
  for (int i = 0; i < sizeof(hashMap)/sizeof(hashMap[0]); ++i)
  {
    if (hashMap[i] != NULL)
    {
      Node* pNode = hashMap[i];
      while (pNode != NULL)
      {
        outStream << *(pNode->item);
        pNode = pNode->next;
      }
    }
  }
}

template <class ItemType>
Hash<ItemType>::Hash()
{
  for (int i = 0; i < sizeof(hashMap)/sizeof(hashMap[0]); ++i)
  {
    hashMap[i] = NULL;
  }
}
template <class ItemType>
Hash<ItemType>::~Hash()
{
  Clear();
}

template <class ItemType>
void Hash<ItemType>::Clear()
{
  for (int i = 0; i < sizeof(hashMap)/sizeof(hashMap[0]); ++i)
  {
    if (hashMap[i] != NULL)
    {
      Node* pNode = hashMap[i];
      while (pNode != NULL)
      {
        Node* delNode = pNode;
        pNode = pNode->next;
        delete delNode->item;
        delete delNode;
      }
    }
  }
}

template <class ItemType>
ItemType* Hash<ItemType>::getItem(string key) const
{
  int mapValue = stringToHashValue(key);

  Node* pNode = hashMap[mapValue];
  while (pNode != NULL)
  {
    if (pNode->key == key)
    {
      return pNode->item;
    }
    pNode = pNode->next;
  }
  return NULL;
}

template <class ItemType>
bool Hash<ItemType>::setItem(string key, ItemType* insItem)
{
  int mapValue = stringToHashValue(key);

  Node* pNode = hashMap[mapValue];
  if (pNode == NULL)
  {
    Node* insNode = new Node();
    insNode->next = NULL;
    insNode->item = insItem;
    insNode->key = key;
    hashMap[mapValue] = insNode;
    return true;
  }
  if (pNode->key == key)
  {
    ItemType* delItem = pNode->item;
    pNode->item = insItem;
    delete delItem;
    return true;
  }
  while (pNode->next != NULL)
  {
    //Overwrite existing hash value
    if ((pNode->next)->key == key)
    {
      ItemType* delItem = pNode->item;
      pNode->item = insItem;
      delete delItem;
      return true;
    }
    pNode = pNode->next;
  }
  Node* insNode = new Node();
  insNode->next = NULL;
  insNode->item = insItem;
  insNode->key = key;
  pNode->next = insNode;
  return true;
}

template <class ItemType>
int Hash<ItemType>::stringToHashValue(string key)
{
  int hash = 0;

  for (int i = 0; i < key.length(); ++i)
  {
    hash += (int)key.at(i);
  }

  return hash % HASH_SIZE;
}