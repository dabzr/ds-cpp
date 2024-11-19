#include "bitset.hpp"
#include <iostream>

int main() {
  bitset bset(125);
  std::cout << bset.get(124) << "\n";
  bset.flip(124);
  std::cout << bset.get(124) << "\n";
  std::cout << bset.get(128) << "\n";
}
