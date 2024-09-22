#include <cstdio>

template<typename T, typename... Args>
constexpr auto add(const T& arg, const Args&... vals)
{
  if constexpr(sizeof...(vals) > 0) {
    return arg + add(vals...);
  } else {
    return arg;
  }
}

int main()
{
  static_assert(add(2, 3, 4) == 9);
  static_assert(add(2) == 2);
}