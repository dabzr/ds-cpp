#include "stack.hpp"

template<typename T>
dynamic_stack<T>::dynamic_stack() : size(0), capacity(3) { arr = new T[capacity]; }

template<typename T>
dynamic_stack<T>::~dynamic_stack() { delete[] arr; }

template<typename T>
T dynamic_stack<T>::pop() {
    if (is_empty()) throw std::underflow_error("Stack underflow");
    return arr[--size];
}

template<typename T>
void dynamic_stack<T>::push(T value) {
  if (is_full()) resize(len()+1);
  arr[size++] = value;
}

template<typename T>
T dynamic_stack<T>::peek() const{ return arr[size-1]; }

template<typename T>
size_t dynamic_stack<T>::len() const{ return size; }

template<typename T>
bool dynamic_stack<T>::is_empty() const{ return len() == 0; }

template<typename T>
bool dynamic_stack<T>::is_full() const{ return len() == capacity; }

template<typename T>
void dynamic_stack<T>::clear() { size = 0; }

template<typename T>
bool dynamic_stack<T>::contains(T value) {
  for (size_t i = 0; i < len(); i++) {
    if (arr[i] == value) return true;
  }
  return false;
}

template<typename T>
T dynamic_stack<T>::get(size_t index) const{ return arr[index]; }

template<typename T>
void dynamic_stack<T>::resize(size_t newsize) {
  auto arr2 = arr;
  arr = new T[newsize];
  for (size_t i = 0; i < newsize; i++) {
    if (i == size) break;
    arr[i] = arr2[i];
  }
  size = size>=newsize?newsize:size;
  capacity = newsize;
  free(arr2);
}

template class dynamic_stack<int>;
template class dynamic_stack<float>;
