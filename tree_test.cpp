#include "BST.h"
#include <iostream>

int main() {
  BST<int>* bst = new BST<int>();

  bst->insert(5);
  bst->insert(6);
  bst->insert(3);
  bst->insert(2);
  bst->insert(7);
 // bst->insert(12);
  

  bst->print();
  std::cout << "\n";

  bst->remove(7);
  bst->print();

}
