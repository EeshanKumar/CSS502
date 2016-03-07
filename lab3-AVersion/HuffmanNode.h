/**
 * Filename:    HuffmanNode.h
 * Author:      Derrick Maestas
 * Project:     CSS 503 Program 3: The Good Mr. Huffman
 *
 * Description: Header file for the HuffmanNode class
 *
 */

#ifndef LAB3_HUFFMANNODE_H
#define LAB3_HUFFMANNODE_H

// Huffman tree node abstract base class
class HuffmanNode {

public:
    HuffmanNode(unsigned char symbol, int frequency);
    HuffmanNode(HuffmanNode* left, HuffmanNode* right);
    ~HuffmanNode();

    bool isLeaf();

    unsigned char getSymbol() const;
    int getWeight() const;
    HuffmanNode* getLeft();
    HuffmanNode* getRight();

private:
    unsigned char symbol;   // character represented by node
    int weight;             // weight of this node, all characters at or below
    HuffmanNode* leftPtr;   // pointer to the left (zero) subtree
    HuffmanNode* rightPtr;  // pointer to the right (one) subtree

    friend class HuffmanTree;

};

#endif //LAB3_HUFFMANNODE_H