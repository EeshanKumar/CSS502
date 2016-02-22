#!/bin/bash
g++ --std=c++11 Compress.cpp HuffmanEncoder.cpp BitWriter.cpp HuffNode.cpp -o Compress
g++ --std=c++11 Uncompress.cpp HuffmanEncoder.cpp HuffNode.cpp -o Uncompress
