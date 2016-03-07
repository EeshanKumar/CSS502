/**
 * Filename:    HuffmanNode.cpp
 * Author:      Derrick Maestas
 * Project:     CSS 503 Program 3: The Good Mr. Huffman
 *
 * Description: Implementation of the HuffmanNode class. This class defines
 * internal and leaf nodes. Leaf nodes do not have children.
 */

#include "HuffmanNode.h"

/*
 * Function: HuffmanNode
 * -----------------------------------------------------------------------------
 * Constructor for a leaf node.
 */
HuffmanNode::HuffmanNode(unsigned char nodeSymbol, int nodeWeight)
{
    symbol = nodeSymbol;
    weight =  nodeWeight;
    leftPtr = nullptr;
    rightPtr = nullptr;
}

/*
 * Function: HuffmanNode
 * -----------------------------------------------------------------------------
 * Constructor for an internal node.
 */
HuffmanNode::HuffmanNode(HuffmanNode* left, HuffmanNode* right)
{
    symbol = 0;
    weight = left->weight + right->weight;
    leftPtr = left;
    rightPtr = right;
}

/*
 * Function: ~HuffmanNode
 * -----------------------------------------------------------------------------
 * Constructor for an internal node.
 */
HuffmanNode::~HuffmanNode()
{
}

/*
 * Function: isLeaf
 * -----------------------------------------------------------------------------
 * Returns true if this node is a leaf node
 */
bool HuffmanNode::isLeaf()
{
    return (leftPtr == nullptr && rightPtr == nullptr);
}

/*
 * Function: getWeight
 * -----------------------------------------------------------------------------
 * Returns the weight associated with this node.
 */
int HuffmanNode::getWeight() const
{
    return weight;
}

/*
 * Function: getSymbol
 * -----------------------------------------------------------------------------
 * Returns the symbol associated with this node.
 */
unsigned char HuffmanNode::getSymbol() const
{
    return symbol;
}

/*
 * Function: getLeft
 * ------------------------------------------------------------------------------
 * Returns left pointer
 */
HuffmanNode* HuffmanNode::getLeft()
{
    return leftPtr;
}

/*
 * Function: getRight
 * ------------------------------------------------------------------------------
 * Returns right pointer
 */
HuffmanNode* HuffmanNode::getRight()
{
    return rightPtr;
}
