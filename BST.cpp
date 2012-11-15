#include "BST.h"
#include <iostream>
#include <sstream>
#include <list>
#include <math.h>

using std::cout;
using std::endl;
using std::list;

template <typename T>
BST<T>::BST() {
  root = 0;
}

template <typename T>
BST<T>::~BST() {
  
}


template <typename T>
bool BST<T>::find(T v) {
  Node<T>* temp = new Node<T>(v);
  root = temp;  
  return true;
}

template <typename T>
void BST<T>::insert(T v) {
  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;

  while (*curr != 0) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }
  *curr = temp;
}

template <typename T>
void BST<T>::remove(T v) {
  Node<T>** temp = &root;
  //Find the Node
  while(temp != 0 && (*temp)->getValue() != v) {
    if(v < (*temp)->getValue()){
      temp = &((*temp)->getLeftChild());
    }
    else{
      temp = &((*temp)->getRightChild());
    }
  }
  if(temp!= 0){
    Node<T>* nodeToRemove = *temp;
    //Leaf node
    if(nodeToRemove->getLeftChild() == 0 && nodeToRemove->getRightChild() == 0){
      delete nodeToRemove;
      *temp = 0;
    }
    //No right child
    else if(nodeToRemove->getRightChild() == 0){
      *temp = nodeToRemove->getLeftChild();
      delete nodeToRemove;
    }
    //No left child
    else if(nodeToRemove->getLeftChild() == 0){
      *temp = nodeToRemove->getRightChild();
      delete nodeToRemove;
    }
    //Node has two children, use ios
    else{
      //right once
      Node<T>* ios = nodeToRemove->getRightChild();
      //then all the way left
      while(ios->getLeftChild() != 0){
        ios = ios->getLeftChild();
      }
      ios->setLeftChild(*(nodeToRemove->getLeftChild()));
      *temp = nodeToRemove->getRightChild();
      delete nodeToRemove;
    }
  }
}

template <typename T>
void BST<T>::print() {

  postOrderTraversal(root);

}


template <typename T>
int BST<T>::getDepth(Node<T>* n){
  if(n==0){
    return 0;
  }
  else{
    int leftDepth = getDepth(n->getLeftChild());
    int rightDepth = getDepth(n->getRightChild());

    if(leftDepth > rightDepth){
      return leftDepth +1;
    }
    else{
      return rightDepth +1;
    }
  }
}

/*
template <typename T>
void BST<T>::rotateLeft(Node<T>** parent){
  Node<T>* crit = *parent;
  Node<T>* tempRC = crit->getRightChild();
  //Node<T>* tempLC = tempRC->getLeftChild();
  tempRC->setLeftChild(crit);
  crit->setRightChild(tempRC);
  *parent = *tempRC;
  
  tempRC->setBalance(0); 
  
}

template <typename T>
void BST<T>::rotateRight(Node<T>** parent){

}

*/

template <typename T>
void BST<T>::preOrderTraversal(Node<T>* root){
  if (root != 0){
    std::cout << root->getValue() << ", " << root->getBalance() << std::endl;
    preOrderTraversal(root->getLeftChild());
    preOrderTraversal(root->getRightChild());
  }

}

template <typename T>
void BST<T>::inOrderTraversal(Node<T>* root){
  if (root != 0){
    inOrderTraversal(root->getLeftChild());
    std::cout << root->getValue() << ", " << root->getBalance() << std::endl; 
    inOrderTraversal(root->getRightChild());
  }

}

template <typename T>
void BST<T>::postOrderTraversal(Node<T>* root){
  if (root != 0){
    postOrderTraversal(root->getLeftChild());
    postOrderTraversal(root->getRightChild());
    std::cout << root->getValue() << ", " << root->getBalance() << std::endl; 
  }
}
template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
    traversalPrint(root->getLeftChild());
    std::cout << root->getValue() << std::endl;
    traversalPrint(root->getRightChild());
  }
}

template class BST<int>;
template class BST<double>;
template class BST<std::string>;
