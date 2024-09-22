#include <iostream>

template<typename... Ts>
void Print(const Ts&... vals)
{
  (..., (std::cout << ' ' << vals));
}

int main() { Print("Hello", "C++", 20); }