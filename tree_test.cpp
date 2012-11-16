#include "BST.h"
#include <iostream>

int main() {
  BST<int>* bst = new BST<int>();

  bst->insert(10);
  bst->insert(5);
  bst->insert(6);
  bst->insert(8);
  bst->insert(11);
  bst->insert(7);
  bst->insert(12);
  bst->insert(4);
  bst->insert(9);

  bst->remove(10);

  bst->print();
  std::cout << "\n"; 
 


}
