#include <iostream>
#include <istream>

class HeapInt {
public:
  HeapInt();
  HeapInt(int data);
  ~HeapInt();
  // Copy
  HeapInt(const HeapInt &);
  HeapInt &operator=(const HeapInt &);
  // Assign
  HeapInt &operator=(int data);

  // Arithmetic Operations
  HeapInt operator+(const HeapInt &hi) const;
  HeapInt operator-(const HeapInt &hi) const;

  bool operator==(const HeapInt &hi) const;

  // IO operations
  friend std::istream &operator>>(std::istream &is, HeapInt &hi);
  friend std::ostream &operator<<(std::ostream &os, const HeapInt &hi);

private:
  int *mData;
};
