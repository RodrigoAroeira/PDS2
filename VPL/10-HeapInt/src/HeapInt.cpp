#include "HeapInt.hpp"

HeapInt::HeapInt() : mData(new int(0)) {}
HeapInt::HeapInt(int data) : mData(new int(data)) {}
HeapInt::~HeapInt() { delete mData; }

HeapInt::HeapInt(const HeapInt &hi) : mData(new int(*hi.mData)) {}
HeapInt &HeapInt::operator=(const HeapInt &hi) {
  *mData = *hi.mData;

  return *this;
}

HeapInt &HeapInt::operator=(int data) {
  *mData = data;
  return *this;
}

HeapInt HeapInt::operator+(const HeapInt &hi) const {
  return HeapInt(*mData + *hi.mData);
}

HeapInt HeapInt::operator-(const HeapInt &hi) const {
  return HeapInt(*mData - *hi.mData);
}

bool HeapInt::operator==(const HeapInt &hi) const {
  return *mData == *hi.mData;
}

std::istream &operator>>(std::istream &is, HeapInt &hi) {
  int val;
  is >> val;
  hi = val;
  return is;
}

std::ostream &operator<<(std::ostream &os, const HeapInt &hi) {
  os << *hi.mData;
  return os;
}
