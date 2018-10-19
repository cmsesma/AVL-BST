#include "AVL.h"
#include "BST.cpp"

#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>

#include "json.hpp"


using namespace std;

void AVL::insertFunct(int key){
  balancingFunct(BST::Insert(key));
    // root_ = insert(root_, nullptr, key);

    //std::cout << key << " & " << size_ << std::endl;
//  if (root_ == nullptr) {
//    root_ = std::make_shared<BSTNode>(key);
//    size_++;
//    return;
//  }
//  std::shared_ptr<BSTNode> currentNode = root_, lastNode = nullptr;
//  while (currentNode != nullptr) {
//    lastNode = currentNode;
//    currentNode = (key < currentNode->key_) ?
//                  currentNode->left_ : currentNode->right_;
//  }
//  if (key < lastNode->key_) {
//    lastNode->left_ = std::make_shared<BSTNode>(key, lastNode);
//  } else {
//    lastNode->right_ = std::make_shared<BSTNode>(key, lastNode);
//  }
//  size_++;
//

}
int AVL::max(int a, int b) {
  return (a > b) ? a : b;
}


/*std::shared_ptr<BSTNode> minValueNode(std::shared_ptr<BSTNode> node) {
  std::shared_ptr<BSTNode> current = node;

  while (current->left_ != nullptr)
    current = current->left_;

  return current;
}*/


int AVL::height(std::shared_ptr<BSTNode> root){
  int lRoot=0;
  int rRoot=0;
  if(root == nullptr){
    return -1;
  }

  //compare heigvht of the left and right
  if(root->HasRightChild()){
    rRoot =  rRoot + height(root->right_) + 1;
  }

  if(root->HasLeftChild()){
    lRoot =  lRoot + height(root->left_) + 1;
  }
  //returning the max
  return lRoot>rRoot ? lRoot : rRoot;

  /*if (node->HasLeftChild()){
   leftside = leftside + height(node->left_) + 1;
 }
 if (node->HasRightChild()){
   rightside = rightside + height(node->right_) + 1;
 }

 if ( leftside > rightside){
   return leftside;
 }
 else {
   return  rightside;
 }*/
}


void AVL::printingFunct(){
  nlohmann::json json = BST::JSON();
  //std::cout << json.dump(2) + "\n";
  int newH = 0;
  for(auto i = json.begin(); i != json.end(); ++i){ //iterating thru jason object
    if(i.key() != "root" && i.key() != "size"){ //if not root or size
      //entering if statements

      int key = atoi(i.key().c_str());
      std::shared_ptr<BSTNode> root = BST::Find(key);


      int h = height(root);
/*
      result[key]["height"] = h;
      result[key]["balance factor"] = balanceF;
      if (v->left_ != nullptr) {
        result[key]["left"] = v->left_->key_;
        nodes.push(v->left_);
      }*/

      int bfV = height(root->right_) - height(root->left_); //finding BF value
      json[i.key()]["height"] = h; //assigning
      json[i.key()]["balance factor"] = bfV; //assigning
      if(key == BST::root_->key_){
      //in if statement

        newH = h; //assigning
      }
    }
  }
  json["height"] = newH;
  std::cout << json.dump(2) + "\n";


/*
  //nlohmann::json json1 = BST::JSON();
  int maxH = 0;
  nlohmann::json result;
  std::queue< std::shared_ptr<BSTNode> > nodes;
  if (root_ != nullptr) {
    result["root"] = root_->key_;
    nodes.push(root_);
    while (!nodes.empty()) {
      auto v = nodes.front();
      nodes.pop();
      std::string key = std::to_string(v->key_);
      int h = height(v);
      if(maxH < h) {
        maxH = h;
      }
      int balanceF = getBalance(v);
      result[key]["height"] = h;
      result[key]["balance factor"] = balanceF;
      if (v->left_ != nullptr) {
        result[key]["left"] = v->left_->key_;
        nodes.push(v->left_);
      }
      if (v->right_ != nullptr) {
        result[key]["right"] = v->right_->key_;
        nodes.push(v->right_);
      }
      if (v->parent_.lock() != nullptr) {
        result[key]["parent"] = v->parent_.lock()->key_;
      } else {
        result[key]["root"] = true;
      }
    }
  }
//  int h = height(newNode);
  result["height"] = maxH;
//  result["root"] = ;
  result["size"] = size_;

  std::cout << result.dump(2) + "\n";*/

}


void AVL::balancingFunct(std::shared_ptr<BSTNode> root){
  int bfV = 0;
  int key_ = 0;

  //std::cout << "HERE" << std::endl;
  if(root != nullptr){
    key_ = root->key_;
  }
  while(root != nullptr && (bfV == -1 || bfV == 0 || bfV == 1)){

    int l = height(root->left_);
    int r = height(root->right_);

    bfV = r - l;
    if(bfV*bfV > 1){
      //std::cout << "----------HERE" << std::endl;

      break;
    }
    else{
      root = root->parent_.lock();
    }
  }
  if(bfV*bfV < 2 || root == nullptr){
    //std::cout << "in if statement here" << std::endl;

    return;
  }

  if(bfV < -1){
    if(key_ < root->left_->key_){
      //std::cout << "HERE!!!!!" << std::endl;

      rotateR(root);
    }
    else if( key_ > root->left_->key_ && key_ < root->key_){
      rotateL(root->left_);

      rotateR(root);

    }
  }
  else if(bfV > 1){
    //std::cout << "in else if statement down" << std::endl;

    if(key_ > root->right_->key_){

      rotateL(root);
    }
    else if(key_ > root->key_ && key_ < root->right_->key_){
      //std::cout << "made it here" << std::endl;

      rotateR(root->right_);
      rotateL(root);
    }
  }
  //std::cout << "ending" << std::endl;




/*
  //BF NODE
  if (node == nullptr) { //node is leaf then BF is 0, no right or left children
    return 0;
  }
*//*  else if (!(node->HasRightChild())){ //has no right child
    return ( (-1) - height(node->left_) );
  }
  else if (!(node->HasLeftChild())){ //has no left child
    return ( height(node->right_) - (-1) ) ;
  }*//*

  return ( height(node->right_) - height(node->left_) ) ;*/



  balancingFunct(root);
}



void AVL::rotateR(std::shared_ptr<BSTNode> root){
  std::shared_ptr<BSTNode> pivot = root->left_;
  if(root->key_ == BST::root_->key_){
    BST::root_ = pivot;
  }
  root->left_ = pivot->right_;

  if (root->left_ != nullptr){
    root->left_->parent_ = root;
  }

  pivot->right_ = root;
  pivot->parent_ = root->parent_;

  /*  root->left_ = left->right_;
  left->right_ = root;
  left->parent_ = root->parent_;*/

  if(root->parent_.lock() != nullptr){
    root->parent_.lock()->ReplaceChild(root, pivot);
  }
  root->parent_ = pivot;





  /*if(left == nullptr || root == nullptr){
    std::cout << "hi";
  }
  if (root->key_ == BST::root_->key_){
    BST::root_ = left;
  }

  if (root->parent_.lock() != nullptr){
    root->parent_.lock()->ReplaceChild(root, left);
  }


  root->parent_ = left;
  return root;*/

}






void AVL::rotateL(std::shared_ptr<BSTNode> root){
  //std::cout << "in rotateL function" << std::endl;


  std::shared_ptr<BSTNode> pivot = root->right_;
  if(root->key_ == BST::root_->key_){
    BST::root_ = pivot;
  }
  if(pivot == nullptr){
    std::cout << "hi" << std::endl;
  }
  root->right_ = pivot->left_;
  if (root->right_ != nullptr){
    root->right_->parent_ = root;
  }
  pivot->left_ = root;
  pivot->parent_ = root->parent_;


  /*root->right_ = pivot->left_;
 pivot->left_ = root;
 pivot->parent_ = root->parent_;*/

  if(root->parent_.lock() != nullptr){
    root->parent_.lock()->ReplaceChild(root, pivot);
  }
  root->parent_ = pivot;




  //resetting


//  root->right_ = pivot->left_;
//  pivot->left_ = root;




/*  std::shared_ptr<BSTNode> pivot = root->right_;
  if (root->key_ == BST::root_->key_){
    BST::root_ = pivot;
  }


  if (root->parent_.lock() != nullptr){
    root->parent_.lock()->ReplaceChild(root, pivot);
  }
  root->parent_ = pivot;
  return root;*/


  //root->parent_ = pivot; //setting parent
}



/*
std::shared_ptr<BSTNode> deleteNode(std::shared_ptr<BSTNode> root, int key)
{
  // STEP 1: PERFORM STANDARD BST DELETE
  if (root == nullptr)
    return root;

  // If the key to be deleted is smaller than
  // the root's key, then it lies in left subtree
  if (key < root->key_)
    root->left_ = deleteNode(root->left_, key);

    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
  else if (key > root->key_)
    root->right_ = deleteNode(root->right_, key);

    // if key is same as root's key, then this is the node
    // to be deleted
  else
  {
    // node with only one child or no child
    if ((root->left_ == nullptr) || (root->right_ == nullptr))
    {
      std::shared_ptr<BSTNode> temp = nullptr;
      if (temp == root->left_)
        temp = root->right_;
      else
        temp = root->left_;

      // No child case
      if (temp == nullptr)
      {
        temp = root;
        root = nullptr;
      }
      else   // One child case
        root = temp; // Copy the contents of
      // the non-empty child
    }
    else
    {

      // node with two children: Get the inorder
      // successor (smallest in the right subtree)
      std::shared_ptr<BSTNode> temp = minValueNode(root->right_);

      // Copy the inorder successor's data to this node
      root->key_ = temp->key_;

      // Delete the inorder successor
      root->right_ = deleteNode(root->right_, temp->key_);
    }
  }

  // If the tree had only one node then return
  if (root == nullptr)
    return root;

  // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
  root->height = max(height(root->left_), height(root->right_)) + 1;

  // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
  //  this node became unbalanced)
  int balance = getBalance(root);

  // If this node becomes unbalanced, then there are 4 cases
  // Left Left Case
  if (balance > 1 && getBalance(root->left_) >= 0)
    return rightRotate(root);

  // Left Right Case
  if (balance > 1 && getBalance(root->left_) < 0)
  {
    root->left_ = leftRotate(root->left_);
    return rightRotate(root);
  }

  // Right Right Case
  if (balance < -1 && getBalance(root->right_) <= 0)
    return leftRotate(root);

  // Right Left Case
  if (balance < -1 && getBalance(root->right_) > 0)
  {
    root->right_ = rightRotate(root->right_);
    return leftRotate(root);
  }

  return root;
}
*/
