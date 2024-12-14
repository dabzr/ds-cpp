#include <iostream>
#include "bin_tree.hpp"

int main ()
{
  bin_tree<int> bintree;
  bintree.insert(10);
  bintree.insert(20);
  std::cout << bintree.leftmost()->value << "\n";
}
