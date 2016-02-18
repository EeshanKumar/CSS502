#include <iostream>
using namespace std;

template <class ItemType>
class BST
{
public:

  friend ostream& operator<<(ostream &outStream, const BST<ItemType> &tree)
  {
    return tree.print(outStream, tree.root);
  }

//Constructors + Desctructors
  BST();
  BST(const BST<ItemType> &srcBST);
  ~BST();

//Public Functions
  int InsertOrIncrement(ItemType *item);
  int Count(ItemType targetItem) const;
  int Height() const;
  void ClearTree();
  bool isEmpty() const;

//Operator Overloads
  BST<ItemType>& operator=(const BST<ItemType> &srcTree);
  BST<ItemType> operator+(const BST<ItemType> &srcTree) const;
  BST<ItemType>& operator+=(const BST<ItemType> &srcTree);


private:
  struct Node
  {
    ItemType *item = NULL;
    int count;
    Node *left = NULL;
    Node *right = NULL;
  };
  Node *root = NULL;

  int addToTree(Node* &subTree, const ItemType *item, int count);
  int findAndReturnCount(Node * subTree, const ItemType &item) const;
  void deleteSubTree(Node * &subTree);
  int heightHelper(Node *subTree) const;
  ostream& print(ostream &outStream, Node* subTree) const;
  void copy(Node * &toSubTree, Node *srcSubTree);
  void plusEqualOperatorHelper(Node * subTree);
};



template <class ItemType>
BST<ItemType>::BST()
{
  root = NULL;
}

template <class ItemType>
BST<ItemType>::BST(const BST &srcBST)
{
  root = NULL;
  *this = srcBST;
}

template <class ItemType>
BST<ItemType>::~BST()
{
  this->ClearTree();
}

template <class ItemType>
int BST<ItemType>::InsertOrIncrement( ItemType *item )
{
  return addToTree(this->root, item, 1);
}

//Return the count of the target item requested. If the item is not in the tree return -1.
template <class ItemType>
int BST<ItemType>::Count(ItemType targetItem) const
{
  return findAndReturnCount(this->root, targetItem);
}

template <class ItemType>
void BST<ItemType>::ClearTree()
{
  deleteSubTree(this->root);
}

template <class ItemType>
bool BST<ItemType>::isEmpty() const
{
  return (this->root == NULL);
}

template <class ItemType>
int BST<ItemType>::Height() const
{
  return heightHelper(this->root);
}

template <class ItemType>
int BST<ItemType>::heightHelper(Node *subTree) const
{
  if (subTree == NULL)
  {
    return 0;
  }
  return 1 + max(heightHelper(subTree->left), heightHelper(subTree->right));
}

template <class ItemType>
int BST<ItemType>::addToTree(Node* &subTree, const ItemType *item, int count)
{
  if (subTree == NULL)
  {
    Node *insNode = new Node();
    ItemType *insItem = new ItemType(*item);
    insNode->item = insItem;
    insNode->count = count;
    subTree = insNode;
    return subTree->count;
  }
  if (*(subTree->item) == *item)
  {
    subTree->count += count;
    return subTree->count;
  }
  if (*item < *(subTree->item))
  {
    return addToTree(subTree->left, item, count);
  }
  if (*item > *(subTree->item))
  {
    return addToTree(subTree->right, item, count);
  }
}

template <class ItemType>
int BST<ItemType>::findAndReturnCount(Node* subTree, const ItemType &item) const
{
  if (subTree == NULL)
  {
    return -1;
  }
  if (*(subTree->item) == item)
  {
    return subTree->count;
  }
  if (item < *(subTree->item))
  {
    return findAndReturnCount(subTree->left, item);
  }
  if (item > *(subTree->item))
  {
    return findAndReturnCount(subTree->right, item);
  }
}

template <class ItemType>
void BST<ItemType>::deleteSubTree(Node* &subTree)
{
  if (subTree == NULL) {
    return;
  }
  deleteSubTree(subTree->left);
  deleteSubTree(subTree->right);
  delete subTree->item;
  subTree->item = NULL;
  delete subTree;
  subTree = NULL;
}

template <class ItemType>
ostream& BST<ItemType>::print(ostream &outStream, Node* subTree) const
{
  if (subTree == NULL)
  {
    return outStream;
  }
  ItemType *printItem = subTree->item;

  print(outStream, subTree->left);
  outStream << subTree->count << " " << *printItem << endl;
  print(outStream, subTree->right);
  return outStream;
}

template <class ItemType>
BST<ItemType>& BST<ItemType>::operator=(const BST<ItemType> &srcTree)
{
  if (this == &srcTree)
  {
    return *this;
  }
  this->ClearTree();
  this->root = NULL;
  this->copy(this->root, srcTree.root);
  return *this;
}

template <class ItemType>
void BST<ItemType>::copy(Node * &toSubTree, Node *srcSubTree)
{
  if (srcSubTree == NULL)
  {
    return;
  }
  Node *insNode = new Node();
  ItemType *insItem = new ItemType();
  *insItem = *(srcSubTree->item);
  insNode->item = insItem;
  insNode->count = srcSubTree->count;
  toSubTree = insNode;
  copy(toSubTree->left, srcSubTree->left);
  copy(toSubTree->right, srcSubTree->right);
}

template <class ItemType>
BST<ItemType> BST<ItemType>::operator+(const BST<ItemType> &srcTree) const
{
  BST<ItemType> returnTree;
  returnTree = *this;
  returnTree += srcTree;
  return returnTree;
}

template <class ItemType>
BST<ItemType>& BST<ItemType>::operator+=(const BST<ItemType> &srcTree)
{
  plusEqualOperatorHelper(srcTree.root);
  return *this;
}

template <class ItemType>
void BST<ItemType>::plusEqualOperatorHelper(Node * subTree)
{
  if (subTree == NULL)
  {
    return;
  }
  this->addToTree(this->root, subTree->item, subTree->count);
  this->plusEqualOperatorHelper(subTree->left);
  this->plusEqualOperatorHelper(subTree->right);
}
