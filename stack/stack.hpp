#include <stdexcept>
#include <stdlib.h>

template<typename T>
class static_stack {
  private:
    size_t size;
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
class dynamic_stack {
  private:
    size_t size;
    size_t capacity;
    T* arr;
    void resize(size_t newsize); 
    bool is_full() const;
  public:
    dynamic_stack();
    ~dynamic_stack();
    T pop();
    void push(T value);
    T peek() const;
    size_t len() const;
    bool is_empty() const;
    void clear();
    bool contains(T value);
    T get(size_t index) const;
};
