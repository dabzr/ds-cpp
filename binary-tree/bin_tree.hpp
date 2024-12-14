#pragma once
#include <cstdint>
#include "node.hpp"

template<typename T>
class bin_tree 
{  
  public:
    // ~bin_tree();
    void insert(T value);
    void remove(T value);
    void print();
    node<T>* leftmost();
    node<T>* rightmost();
    node<T>* next();
  private:
    node<T>* root = nullptr;
    uint32_t node_quantity = 0;
};

#include "../stack/static_stack.hpp"

template<typename T>
void bin_tree<T>::insert(T value) 
{
  if (!root)
  {
    root = new node<T>;
    root->value = value;
    node_quantity++;
    return;
  }

  static_stack<node<T>*> stack(node_quantity);
  stack.push(root);
  
  while (!stack.is_empty())
  {
    node<T>* nd = stack.pop();
    
    if (!nd->lhs)
    {
      nd->add_left(value);
      node_quantity++;
      return;
    }

    if (!nd->rhs)
    {
      nd->add_right(value);
      node_quantity++;
      return;
    }
    
    stack.push(nd->rhs);
    stack.push(nd->lhs);
  }
}

template<typename T>
node<T>* bin_tree<T>::leftmost()
{
  node<T>* nd = root->lhs;
  node<T>* temp = nd;
  while (nd)
  {
    temp = nd;
    nd = nd->lhs;
  }
  return temp;
} 

