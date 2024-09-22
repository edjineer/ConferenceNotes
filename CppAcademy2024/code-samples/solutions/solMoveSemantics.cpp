#include <algorithm>
#include <chrono>
#include <iostream>
#include <utility>
#include <vector>

class BigArray {
  size_t len_{};
  int*   data_{};

public:
  explicit BigArray(size_t len)
  : len_{len}
  , data_{new int[len]{3}}  // ensure that Linux _does_ allocated memory
  {}

  BigArray(const BigArray& other)
  : len_{other.len_}
  , data_{new int[other.len_]}
  {
    std::cout << "Copy construction of " << other.len_ << " elements\n";
    std::copy_n(other.data_, len_, data_);
  }

  BigArray& operator=(const BigArray& other)
  {
    std::cout << "Copy assignment of " << other.len_ << " elements\n";
    if(this != &other) {
      delete[] data_;

      len_  = other.len_;
      data_ = new int[len_];
      std::copy_n(other.data_, len_, data_);
    }

    return *this;
  }

  BigArray(BigArray&& other) noexcept
  : len_{std::exchange(other.len_, 0)}
  , data_{std::exchange(other.data_, nullptr)}
  {
    std::cout << "Move construction of " << len_ << " elements\n";
  }

  BigArray& operator=(BigArray&& other) noexcept
  {
    std::cout << "Move assignment of " << other.len_ << " elements\n";
    if(this != &other) {
      len_  = std::exchange(other.len_, 0);
      data_ = std::exchange(other.data_, data_);
    }

    return *this;
  }

  ~BigArray() { delete[] data_; }
};

int main()
{
  std::vector<BigArray> myVec{};

  const auto start = std::chrono::system_clock::now();

  myVec.push_back(BigArray{1'000'000'000});

  const auto end = std::chrono::system_clock::now();
  using fsec     = std::chrono::duration<double>;

  const fsec elapsed{end - start};
  std::cout << "elapsed time: " << elapsed.count() << "s\n";
}