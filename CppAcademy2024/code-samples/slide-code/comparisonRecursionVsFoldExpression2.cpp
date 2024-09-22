#include <iostream>

template<typename... Ts>
void Print(const Ts&... vals)
{
  auto coutSpaceAndArg = [](const auto& arg) {
    std::cout << ' ' << arg;
  };

  (..., coutSpaceAndArg(vals));
}

int main() { Print("Hello", "C++", 20); }