#include <cstdio>
#include <type_traits>

template<typename T, typename... Args>
auto add(const T& arg, const Args&... vals)
{
  static_assert(std::is_unsigned_v<T>, "T must be an integral type");

  if constexpr(sizeof...(vals) > 0) {
    return arg + add(vals...);
  } else {
    return arg;
  }
}

int main()
{
  printf("%d\n", add(2u, 3u, 4u));

  printf("%d\n", add(2u));

  // fail due to static_assert
  // printf("%lf\n", add(2.0, 3.0, 4.0));
  // printf("%lf\n", add(2.0));
}