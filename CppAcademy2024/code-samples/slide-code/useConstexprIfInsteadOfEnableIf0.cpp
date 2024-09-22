#include <cstdio>
#include <type_traits>

struct Object {};

template<typename T>
std::enable_if_t<std::is_integral_v<T>>
process(T&& value)
{
  puts("integral");
}

template<typename T>
std::enable_if_t<not std::is_integral_v<T>>
process(T&& value)
{
  puts("not integral");
}

int main()
{
  process(Object{});
  process(42);
}