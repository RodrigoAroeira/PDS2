#include <iostream>

template <typename T>
class Vetor {
public:
  explicit Vetor(size_t size) : mData(new T[size]), mSize(0), mCapacity(size) {}

  ~Vetor() { delete[] mData; }

  Vetor(const Vetor &v)
      : mData(new T[v.mSize]), mSize(v.mSize), mCapacity(v.mCapacity) {
    for (int i{}; i < (int)mSize; ++i) {
      mData[i] = v.mData[i];
    }
  }

  size_t getSize() const { return mSize; }

  void SetElemento(size_t pos, T element) { mData[pos] = element; }

  T &GetElemento(size_t pos) { return mData[pos]; };
  const T &GetElemento(size_t pos) const { return mData[pos]; }

  void AdicionaElemento(T elemento) { mData[mSize++] = elemento; }

  friend std::ostream &operator<<(std::ostream &os, const Vetor &v) {
    int n = v.getSize();
    for (int i{}; i < n; ++i) {
      os << v[i] << (i < n - 1 ? " " : "");
    }
    return os;
  }

  void Imprime() const { std::cout << *this << std::endl; }

  T &operator[](size_t pos) { return GetElemento(pos); }
  const T &operator[](size_t pos) const { return GetElemento(pos); }

private:
  T *mData;
  size_t mSize;
  size_t mCapacity;
};
