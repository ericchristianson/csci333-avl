#ifndef __BST_H__
#define __BST_H__

#include "Node.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

template <typename T>
class BST {
 private:
  Node<T>* root;
  void traversalPrint(Node<T>* root);
  int getDepth(Node<T>* n);
  void rotateLeft(Node<T>** crit);
  void rotateRight(Node<T>** crit);
  void preOrderTraversal(Node<T>* root);
  void inOrderTraversal(Node<T>* root);
  void postOrderTraversal(Node<T>* root);

 public:
  BST<T>();
  ~BST<T>();

  bool find(T v);
  void remove(T v);
  void insert(T v);
  void print();
};


#endif
