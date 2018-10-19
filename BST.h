//
// Created by Chelsy Sesma on 5/29/18.
//

#ifndef HOMEWORK3_BST_H
#define HOMEWORK3_BST_H


#include <memory>
#include <string>
#include "json.hpp"


class BST;

class BSTNode {
 public:
  BSTNode(int key);
  BSTNode(int key, std::weak_ptr<BSTNode> parent);
  bool IsLeaf() const;
  bool IsMissingChild() const;
  bool HasLeftChild() const;
  bool HasRightChild() const;
  void DeleteChild(std::shared_ptr<BSTNode> v);
  void ReplaceChild(std::shared_ptr<BSTNode> v, std::shared_ptr<BSTNode> u);
  int key_;
  int height;
  std::weak_ptr<BSTNode> parent_;
  std::shared_ptr<BSTNode> left_;
  std::shared_ptr<BSTNode> right_;

  friend BST;
}; // class BSTNode

class BST {
 public:
  BST();

  std::shared_ptr<BSTNode> Insert(int key);
  std::shared_ptr<BSTNode> Delete(int key);
  std::shared_ptr<BSTNode> Find(int key) const;
  nlohmann::json JSON() const;
  size_t size() const;
  bool empty() const;
  int DeleteMin();


  void DeleteLeaf(std::shared_ptr<BSTNode> currentNode);
  int DeleteMin(std::shared_ptr<BSTNode> currentNode);

  std::shared_ptr<BSTNode> root_;
  size_t size_;
}; // class BST


#endif //HOMEWORK3_BST_H
