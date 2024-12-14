#include "static_stack.hpp"
#include "dynamic_stack.hpp"
#include <iostream>

int main() {
  static_stack<int> sstack(5);
  sstack.push(5);
  sstack.push(9);
  sstack.push(10);
  std::cout << sstack.pop() << "\n" << sstack.peek() << "\n";
  sstack.push(11);
  sstack.push(12);
  sstack.push(13);
  dynamic_stack<int> dstack;
  dstack.push(5);
  dstack.push(6);
  dstack.push(7);
  dstack.push(8);
  std::cout << dstack.pop() << "\n";
  return 0;
}
