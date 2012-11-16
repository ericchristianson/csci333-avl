#include "BST.h"
#include <iostream>

int main() {
  BST<int>* bst = new BST<int>();

  bst->insert(10);
  bst->insert(5);
 
  bst->print();
  std::cout << "\n"; 
  
  bst->insert(4);
 
  bst->print();
  std::cout << "\n"; 
  
  bst->insert(3);
 
  bst->print();
  std::cout << "\n"; 
  bst->insert(2);

  bst->print();
  std::cout << "\n"; 
 
  bst->insert(1);
  

  bst->print();
  std::cout << "\n";

  //bst->remove(7);
  //bst->print();

}
