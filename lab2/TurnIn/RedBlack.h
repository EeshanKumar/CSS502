#include <iostream>
using namespace std;

template <class ItemType>
class BST
{
public:

  template <class T>
  friend ostream& operator<<(ostream &outStream, const BST<T> &tree);

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

//Operator Overload
  BST<ItemType>& operator=(const BST<ItemType> &srcTree);
  BST<ItemType> operator+(const BST<ItemType> &srcTree) const;
  BST<ItemType>& operator+=(const BST<ItemType> &srcTree);


private:
  enum Color { black, red };
  struct Node
  {
    ItemType *item = NULL;
    int count;
    Node *left = NULL;
    Node *right = NULL;
    Node *parent = NULL;
    Color color = red;
  };
  Node *root = NULL;

  int addToTree(Node* &subTree, Node* parentNode, const ItemType *item, int count);
  typename BST<ItemType>::Node* grandparent(Node* subTree);
  typename BST<ItemType>::Node* uncle(Node* subTree);
  void verifyProperties(Node* subTree);
  void case1(Node* subTree);
  void case2(Node* subTree);
  void case3(Node* subTree);
  void case4(Node* subTree);
  void case5(Node* subTree);
  void rotateOnParent(Node* subTree, bool left);

  int findAndReturnCount(Node * subTree, const ItemType &item) const;
  void deleteSubTree(Node * &subTree);
  int heightHelper(Node *subTree) const;
  ostream& print(ostream &outStream, Node* subTree) const;
  void copy(Node * &toSubTree, Node * toSubTreeParent, Node *srcSubTree);
  void plusEqualOperatorHelper(Node * subTree);
};

template <class T>
ostream& operator<<(ostream &outStream, const BST<T> &tree)
{
  return tree.print(outStream, tree.root);
}


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
  return addToTree(this->root, NULL, item, 1);
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
int BST<ItemType>::addToTree(Node* &subTree, Node* parentNode, const ItemType *item, int count)
{
  if (subTree == NULL)
  {
    Node *insNode = new Node();
    ItemType *insItem = new ItemType(*item);
    insNode->item = insItem;
    insNode->count = count;
    insNode->color = red;
    insNode->parent = parentNode;
    subTree = insNode;
    verifyProperties(subTree);
    return count;
  }
  if (*(subTree->item) == *item)
  {
    subTree->count += count;
    return subTree->count;
  }
  if (*item < *(subTree->item))
  {
    return addToTree(subTree->left, subTree, item, count);
  }
  if (*item > *(subTree->item))
  {
    return addToTree(subTree->right, subTree, item, count);
  }
}

template <class ItemType>
typename BST<ItemType>::Node* BST<ItemType>::grandparent(Node* subTree)
{
  if ((subTree != NULL) && (subTree->parent != NULL))
  {
    return subTree->parent->parent;
  }
  return NULL;
}

template <class ItemType>
typename BST<ItemType>::Node* BST<ItemType>::uncle(Node* subTree)
{
  Node* gNode = grandparent(subTree);
  if (gNode == NULL)
  {
    return NULL;
  }
  if (subTree->parent == gNode->left)
  {
    return gNode->right;
  }
  return gNode->left;
}

template <class ItemType>
void BST<ItemType>::verifyProperties(Node* subTree)
{
  case1(subTree);
}

template <class ItemType>
void BST<ItemType>::case1(Node* subTree)
{
  //Case 1
  if (subTree->parent == NULL)
  {
    subTree->color = black;
  }
  else
  {
    case2(subTree);
  }
}

template <class ItemType>
void BST<ItemType>::case2(Node* subTree)
{
  //Case 2
  if (subTree->parent->color != black)
  {
    case3(subTree);
  }
}

template <class ItemType>
void BST<ItemType>::case3(Node* subTree)
{
  Node* pParent = subTree->parent;
  Node* pGrandparent = grandparent(subTree);
  Node* pUncle = uncle(subTree);

  //Case 3
  if ((pUncle != NULL) && (pUncle->color == red))
  {
    pParent->color = black;
    pUncle->color = black;
    pGrandparent->color = red;
    case1(pGrandparent);
  }
  else
  {
    case4(subTree);
  }
}

template <class ItemType>
void BST<ItemType>::case4(Node* subTree)
{
  Node* pParent = subTree->parent;
  Node* pGrandparent = grandparent(subTree);
  bool isNodeRightOfParent = false;
  bool isParentLeftOfGrandparent = false;

  if (pGrandparent == NULL)
  {
    return;
  }

  if (pParent->right == subTree)
  {
    isNodeRightOfParent = true;
  }
  if (pGrandparent->left == pParent)
  {
    isParentLeftOfGrandparent = true;
  }

  //Case 4
  if (isNodeRightOfParent == isParentLeftOfGrandparent)
  {
    // Left rotation on P with P becoming the current node
    if (isNodeRightOfParent && isParentLeftOfGrandparent)
    {
      rotateOnParent(subTree, true);
      case5(pParent);
    }
    else //Both are false so right rotation
    {
      rotateOnParent(subTree, false);
      case5(pParent);
    }
  }
  else
  {
    case5(subTree);
  }
}

template <class ItemType>
void BST<ItemType>::case5(Node* subTree)
{
  Node* pParent = subTree->parent;
  Node* pGrandparent = grandparent(subTree);
  bool isNodeLeftOfParent = false;
  bool isParentLeftOfGrandparent = false;

  if (pGrandparent == NULL)
  {
    return;
  }

  if (pParent->left == subTree)
  {
    isNodeLeftOfParent = true;
  }
  if (pGrandparent->left == pParent)
  {
    isParentLeftOfGrandparent = true;
  }

  //Case 5
  if (isNodeLeftOfParent == isParentLeftOfGrandparent)
  {
    pParent->color = black;
    pGrandparent->color = red;
    // Right rotation on grandparent
    if (isNodeLeftOfParent && isParentLeftOfGrandparent)
    {
      rotateOnParent(pParent, false);
    }
    else //Both are false so left rotation
    {
      rotateOnParent(pParent, true);
    }
  }
}

template <class ItemType>
void BST<ItemType>::rotateOnParent(Node* subTree, bool isLeft)
{
  Node* pLeft = subTree->left;
  Node* pRight = subTree->right;
  Node* pParent = subTree->parent;
  Node* pGrandparent = grandparent(subTree);

  if (pGrandparent != NULL)
  {
    if (pGrandparent->left == pParent)
    {
      pGrandparent->left = subTree;
      subTree->parent = pGrandparent;
    }
    else
    {
      pGrandparent->right = subTree;
      subTree->parent = pGrandparent;
    }
  }
  else //is at root
  {
    this->root = subTree;
    subTree->parent = NULL;
  }

  if (isLeft)
  {
    subTree->left = pParent;
    pParent->parent = subTree;
    pParent->right = pLeft;
    if (pLeft != NULL)
    {
      pLeft->parent = pParent;
    }
  }
  else //right
  {
    subTree->right = pParent;
    pParent->parent = subTree;
    pParent->left = pRight;
    if (pRight != NULL)
    {
      pRight->parent = pParent;
    }
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
  outStream << subTree->count << " " << *printItem << " " << subTree->color << endl;
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
  this->copy(this->root, NULL, srcTree.root);
  return *this;
}

template <class ItemType>
void BST<ItemType>::copy(Node * &toSubTree, Node * toSubTreeParent, Node *srcSubTree)
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
  insNode->color = srcSubTree->color;
  toSubTree = insNode;
  toSubTree->parent = toSubTreeParent;
  copy(toSubTree->left, toSubTree, srcSubTree->left);
  copy(toSubTree->right, toSubTree, srcSubTree->right);
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
  this->addToTree(this->root, NULL, subTree->item, subTree->count);
  this->plusEqualOperatorHelper(subTree->left);
  this->plusEqualOperatorHelper(subTree->right);
}
