#include <iostream>
#include <vector>

int main()
{
  const std::vector<int> numbers{2, 3, 5, 7};

  for(const auto& e : numbers) {
    std::cout << e << '\n';
  }
}