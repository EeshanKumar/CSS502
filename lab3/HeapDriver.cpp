#include <iostream>
using namespace std;
#include "PriorityQueue.h"
#include "HuffNode.h"

int main(int argc, char* argv[])
{
  PriorityQueue<HuffNode> myQueue;
  char a = 100;
  HuffNode huffA(a, 10);
  char b = 101;
  HuffNode huffB(b, 1);
  char c = 104;
  HuffNode huffC(c, 9);
  char d = 106;
  HuffNode huffD(d, 5);
  char e = 107;
  HuffNode huffE(e, 100);
  myQueue.Add(huffB);
  myQueue.Add(huffC);
  myQueue.Add(huffD);
  myQueue.Add(huffA);
  myQueue.Add(huffE);
  cout << myQueue;
  return 0;
}
