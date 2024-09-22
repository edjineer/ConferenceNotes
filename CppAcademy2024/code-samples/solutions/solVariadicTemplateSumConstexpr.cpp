#include <cstdio>

// forward declare primary template
template<int...>
struct add;

// no args specialization
template<>
struct add<> {
  static constexpr int value = 0;
};

// the real template
template<int i, int... tail>
struct add<i, tail...> {
  static constexpr int value = i + add<tail...>::value;
};

int main()
{
  printf("%d\n", add<2, 3, 4>::value);

  printf("%d\n", add<2>::value);

  static_assert(9 == add<2, 3, 4>::value, "Expect 6");
}