#include "bitset.hpp"
#include <stdexcept>

bitset::bitset(size_t size) : bitsize(size) {
  bitcount = sizeof(uint8_t) * 8;
  arrsize = bitsize / bitcount + (bitsize%bitcount != 0);
  arr = new uint8_t[arrsize]();
}

bitset::~bitset() {
  delete [] arr;
}

bool bitset::get(size_t index) {
  if (index >= bitsize) throw std::out_of_range("Index is out of range");
  const size_t arr_index = index / bitcount;
  const size_t bit_index = index - arr_index * bitcount - 1;
  return (arr[arr_index] >> bit_index) & 1;
}

void bitset::flip(size_t index) {
  if (index >= bitsize) throw std::out_of_range("Index is out of range");
  size_t arr_index = index / bitcount;
  size_t bit_index = index - arr_index * bitcount - 1;
  arr[arr_index] ^= (1 << bit_index); 
}

size_t bitset::len() const {return bitsize;}
void bitset::reset() { for (size_t i = 0; i < arrsize; i++) arr[i] = 0; }
