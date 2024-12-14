#pragma once

template<typename T>
class node
{
  public:
    node<T>* lhs = nullptr;
    node<T>* rhs = nullptr;
    T value;
    void add_left(T v);
    void add_right(T v);
};

template<typename T>
void node<T>::add_left(T v)
{
  lhs = new node<T>;
  lhs->value = value;
}

template<typename T>
void node<T>::add_right(T v)
{
  rhs = new node<T>;
  rhs->value = value;
}

