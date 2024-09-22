#include <iostream>

template<typename T, typename... Ts>
void Print(const T& targ, const Ts&... vals)
{
  std::cout << ' ' << targ;

  if constexpr(sizeof...(vals) > 0) { Print(vals...); }
}

int main() { Print("Hello", "C++", 20); }