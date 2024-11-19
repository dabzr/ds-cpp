#include <cstdint>
#include <stdlib.h>

class bitset {
  private:
    size_t arrsize;
    size_t bitsize;
    uint32_t *arr;
    size_t bitcount;
  public:
    bitset(size_t size);
    ~bitset();
    bool get(size_t index);
    void flip(size_t index);
    size_t len() const;
    void reset();
};
