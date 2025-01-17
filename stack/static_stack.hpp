#pragma once
#include <stdlib.h>
#include <stdexcept>

template<typename T>
class static_stack {
  private:
    size_t size = 0;
    const size_t capacity;
    T* arr;

  public:
    static_stack(size_t size);
    ~static_stack();
    T pop();
    void push(T value);
    T peek() const;
    size_t len() const;
    size_t max_len() const;
    bool is_empty() const;
    bool is_full() const;
    void clear();
    bool contains(T value);
    T get(size_t index) const;
};

template<typename T>
static_stack<T>::static_stack(size_t capacity) : size(0), capacity(capacity) { arr = new T[capacity]; }

template<typename T>
static_stack<T>::~static_stack() { delete[] arr; }
template<typename T>
T static_stack<T>::pop() {
    if (is_empty()) throw std::underflow_error("Stack underflow");
    return arr[--size];
}

template<typename T>
void static_stack<T>::push(T value) {
  if (is_full()) throw std::overflow_error("Stack overflow");
  arr[size++] = value;
}

template<typename T>
T static_stack<T>::peek() const{ return arr[size-1]; }

template<typename T>
size_t static_stack<T>::len() const{ return size; }
template<typename T>
size_t static_stack<T>::max_len() const{ return capacity; }
template<typename T>
bool static_stack<T>::is_empty() const{ return len() == 0; }

template<typename T>
bool static_stack<T>::is_full() const{ return len() == max_len(); }

template<typename T>
void static_stack<T>::clear() { size = 0; }

template<typename T>
bool static_stack<T>::contains(T value) {
  for (size_t i = 0; i < len(); i++) {
    if (arr[i] == value) return true;
  }
  return false;
}

template<typename T>
T static_stack<T>::get(size_t index) const{ return arr[index]; }


