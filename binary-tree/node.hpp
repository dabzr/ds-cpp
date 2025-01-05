#pragma once

template<typename T>
class node
{
  public:
    node<T>* lhs = nullptr;
    node<T>* rhs = nullptr;
    T value;
};
