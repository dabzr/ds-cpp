#include "bitset.hpp"
#include <iostream>

int main() {
  bitset bset(128);
  std::cout << bset.get(33) << "\n";
  bset.flip(33);
  std::cout << bset.get(33) << "\n";
}
