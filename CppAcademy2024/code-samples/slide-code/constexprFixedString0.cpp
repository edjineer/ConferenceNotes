#include <algorithm>
#include <cstdint>
#include <string>

// remove for demo
#ifndef CONSTEXPR
#  define CONSTEXPR constexpr
#endif
// remove for demo end

template<size_t N>
class FixedString {
  size_t mLength{};
  char   mData[N]{};

public:
  FixedString() = default;
  CONSTEXPR FixedString(const char* str)
  : mLength{std::char_traits<char>::length(str)}
  {
    std::copy_n(str, size(), mData);
  }

  CONSTEXPR size_t size() const { return mLength; }

  const char* data() const
  {  // std::string_view would be better
    return mData;
  }
};

template<size_t N>
CONSTEXPR auto make_fixed_string(const char (&str)[N])
{
  return FixedString<N>{str};
}

CONSTEXPR static const FixedString<50> x{
  "Hello, embedded World!"};
CONSTEXPR static const auto y{
  make_fixed_string("Hello, some other planet!")};

int main()
{
  printf("x: %s  %lu\n", x.data(), sizeof(x));
  printf("y: %s  %lu\n", y.data(), sizeof(y));
}