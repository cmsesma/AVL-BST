#ifndef HOMEWORK3_AVL_H
#define HOMEWORK3_AVL_H


#include <memory>
#include <string>

#include "BST.h"

class AVL: public BST{



 public:
  void balancingFunct(std::shared_ptr<BSTNode> currentNode);
  int height(std::shared_ptr<BSTNode> currentNode);
  void insertFunct(int key);



  void rotateR(std::shared_ptr<BSTNode> currentNode);
  void rotateL(std::shared_ptr<BSTNode> currentNode);
  void printingFunct();
  int max(int a, int b);
};


#endif //HOMEWORK3_AVL_H