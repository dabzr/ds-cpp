#include <iostream>
#include "bin_tree.hpp"

int main ()
{
  bin_tree<int> bintree;
  bintree.insert(10);
  bintree.insert(20);
  bintree.insert(30);
  bintree.insert(40);
  bintree.insert(50);
  std::cout << bintree.leftmost()->value << "\n";
  std::cout << bintree.rightmost()->value << "\n";
}
