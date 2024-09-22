#include <cstdio>
#include <type_traits>

template<typename T, typename... Ts>
inline constexpr bool are_same_v = std::conjunction_v<std::is_same<T, Ts>...>;

template<typename T, typename... Args>
T add(const T& arg, const Args&... vals)
{
  static_assert(are_same_v<T, Args...>);

  if constexpr(sizeof...(vals) > 0) {
    return arg + add(vals...);
  } else {
    return arg;
  }
}

int main()
{
  printf("%d\n", add(2, 3, 4));

  printf("%d\n", add(2));
}