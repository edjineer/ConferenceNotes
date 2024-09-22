#include <iostream>
#include <vector>

int main()
{
  const std::vector<int> numbers{2, 3, 5, 7};

  for(auto it{numbers.begin()}; it != numbers.end();
      ++it) {
    std::cout << *it << '\n';
  }
}