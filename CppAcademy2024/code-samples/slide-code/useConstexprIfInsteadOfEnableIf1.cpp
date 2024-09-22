#include <cstdio>
#include <type_traits>

struct Object {};

template<typename T>
void process(T&& value)
{
  if constexpr(std::is_integral_v<T>) {
    puts("integral");
  } else if constexpr(not std::is_integral_v<T>) {
    puts("not integral");
  }
}

int main()
{
  process(Object{});
  process(42);
}