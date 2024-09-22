#include <algorithm>
#include <cstdio>
#include <initializer_list>

template<class T, size_t SIZE>
class MyArrayWrapper {
  T      data[SIZE]{};
  size_t size{};

public:
  MyArrayWrapper(std::initializer_list<T> l)
  : size{std::min(l.size(), SIZE)}
  {
    std::copy_n(l.begin(), size, data);
  }

  T* begin() { return &data[0]; }
  T* end() { return &data[size]; }
};

int main()
{
  MyArrayWrapper<int, 10> arr{2, 3, 4, 5};

  for(const int& i : arr) { printf("%d\n", i); }
}