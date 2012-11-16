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
  //Keep track of parent for balance updates
  Node<T>** parent = 0;

  //Find insert location
  while (*curr != 0) {
  
    if(v < (*curr)->getValue()){
      //update balances
      if((*curr)->getLeftChild() != 0){
        (*curr)->setBalance((*curr)->getBalance()-1);
      }

      if((*curr)->getRightChild() != 0){
        (*curr)->setBalance((*curr)->getBalance()+1);
      }
      if((*curr)->getBalance() < 0){
        parent = curr;
      }

      curr = &((*curr)->getLeftChild());
    
    } 
    else if (v > (*curr)->getValue()) {
      //update balances
      if((*curr)->getLeftChild() != 0){
        (*curr)->setBalance((*curr)->getBalance()-1);
      }

      if((*curr)->getRightChild() != 0){
        (*curr)->setBalance((*curr)->getBalance()+1);
      }

      if((*curr)->getBalance() > 0){
        parent = curr;
      }

      curr = &((*curr)->getRightChild());
    }
  }
  *curr = temp;

  //check for critical node
  //if node is critical: 4 cases

  //left cases
  if(parent !=0 && v < (*parent)->getValue()){
    if((*parent)->getLeftChild()->getBalance()>0){
      //left-right = double rotation
      rotateLeft(&((*parent)->getLeftChild()));
      rotateRight(parent);
      (*parent)->setBalance(0);
    }
    else{
      rotateRight(parent);
      (*parent)->setBalance(0);
    }
  }
  
  //right cases
  if(parent !=0 && v > (*parent)->getValue()){
    if((*parent)->getRightChild()->getBalance() > 0){
      //right-left = double rotation
      rotateRight(&((*parent)->getRightChild()));
      rotateLeft(parent);
      (*parent)->setBalance(0);
    }
    else{
      rotateLeft(parent);
      (*parent)->setBalance(0);
    }
  }
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
int BST<T>::getBalance(Node<T>* n){

  if (n==0){
    return 0;
  }
  else{
    int rightTree = getDepth(n->getRightChild());
    int leftTree = getDepth(n->getLeftChild());
    return (rightTree - leftTree);
  }

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

template <typename T>
void BST<T>::rotateLeft(Node<T>** parent){
  Node<T>* tempRC = *parent;
  Node<T>* tempLC = (*parent)->getRightChild()->getLeftChild();
  *parent = tempRC->getRightChild();
  (*parent)->setLeftChild(*tempRC);
  tempRC->setRightChild(*tempLC);

}

template <typename T>
void BST<T>::rotateRight(Node<T>** parent){
  Node<T>* tempRC = *parent;
  Node<T>* tempLC = (*parent)->getLeftChild()->getRightChild();
  *parent = tempRC->getLeftChild();
  (*parent)->setRightChild(*tempRC);
  tempRC->setLeftChild(*tempLC);

}



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

template class BST<int>;
template class BST<double>;
template class BST<std::string>;
