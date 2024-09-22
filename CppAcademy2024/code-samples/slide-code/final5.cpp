#include <iostream>
#include <utility>

namespace gsl {
  template<typename T, typename U>
  T narrow_cast(const U& u)
  {
    return static_cast<T>(u);
  }

}  // namespace gsl

using namespace std;

int Open() { return 0; }

int read(int fd, char* buffer, size_t bufLen)
{
  return 0;
}

int close(int fd) { return 0; }

int ftruncate(int fd, off_t length) { return 0; }

template<typename T>
class span {
public:
  constexpr span() = default;
  constexpr span(T* start, const size_t len)
  : data_{start}
  , length{len}
  {}

  template<size_t N>
  constexpr span(T (&arr)[N])
  : span(arr, N)
  {}

  template<size_t N>
  constexpr span(const T (&arr)[N])
  : span(arr, N)
  {}

  constexpr size_t size() const { return length; }
  T*               data() const { return data_; }
  bool empty() const { return nullptr == data_; }

  T* begin() const { return data_; }
  T* end() const { return data_ + length; }

private:
  T*     data_;
  size_t length;
};

template<typename T>
class FinalAction {
  T mAction;

public:
  explicit FinalAction(T&& action) noexcept
  : mAction{std::forward<T>(action)}
  {}

  ~FinalAction() noexcept { mAction(); }
};

size_t ReadData(span<char> buffer)
{
  int         fd = Open(/*some well known file*/);
  FinalAction cleanup{[&] {
    if(-1 != fd) { close(fd); }
  }};

  if(-1 == fd) { return 0; }

  const auto len =
    read(fd, buffer.data(), buffer.size());

  if(-1 == len) { return 0; }

  ftruncate(fd, len);

  return gsl::narrow_cast<size_t>(len);
}

int main() {}
