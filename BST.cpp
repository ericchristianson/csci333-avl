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
  int maxDepth = getTreeDepth(root); 
  vector<string>* printQ = q();
  int spaces;
  int numElements = 1;
  string currElement;
  string symbols;
  bool slash = true;

  for(int depth=maxDepth; depth>0; --depth){
    spaces = pow(2, depth);
    for(int i=0; i<numElements; ++i){
      currElement = (*printQ)[0];
      for(int j=0; j<spaces; ++j){
        cout << " ";
      }
      if(currElement != "0"){
        cout << currElement;
      }
      else{
        cout << " ";
      }

      for(int k=0; k<spaces/3; ++k){
        symbols += " ";
      }
      if(currElement != "0"){
        if(slash){
          symbols+= "/";
        }
        else{
          symbols += "\\";
        }
      }
      slash = !slash;
      printQ->erase(printQ->begin());
    }
    cout << endl;
    cout << symbols << endl;
    numElements *= 3;
  }
  delete printQ;
}

template <typename T>
vector<string>* BST<T>::q(){

  vector<string> * printQ = new vector<string>;
  list< Node<T>* >* nodeQ = new list< Node<T>* >;
  Node<T>* curr = root;
  nodeQ->push_front(root);
  printQ->push_back(toString(root->getValue()));

  while(!nodeQ->empty()){
    curr = nodeQ->front();
    if(curr->getLeftChild() != 0){
      printQ->push_back(toString(curr->getLeftChild()->getValue()));
      nodeQ->push_back(curr->getLeftChild());
    }
    else{
      printQ->push_back("0");
    }
    if(curr->getRightChild() != 0){
      printQ->push_back(toString(curr->getRightChild()->getValue()));
      nodeQ->push_back(curr->getRightChild());
    }
    else{
      printQ->push_back("0");
    }
    nodeQ->pop_front();
  }
  delete nodeQ;
  return printQ;
}
template <typename T>
int BST<T>::getTreeDepth(Node<T>* n){
  if(n==0){
    return 0;
  }
  else{
    int leftDepth = getTreeDepth(n->getLeftChild());
    int rightDepth = getTreeDepth(n->getRightChild());

    if(leftDepth > rightDepth){
      return leftDepth +1;
    }
    else{
      return rightDepth +1;
    }
  }
}

template <typename T>
string BST<T>::toString(T v){
  std::stringstream ss;
  ss << v;
  return ss.str();
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
