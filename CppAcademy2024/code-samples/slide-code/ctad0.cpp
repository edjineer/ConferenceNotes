#include <utility>
#include <vector>

int main()
{
  // #A Before C++17 <int> was mandatory
  std::vector<int> x{2, 3, 4};

  // #B With CTAD in C++17 the compiler detects the
  // type
  std::vector y{2, 3, 4};

  x = y;
}