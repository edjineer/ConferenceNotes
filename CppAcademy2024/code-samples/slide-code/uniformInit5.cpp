#include <cstdio>
#include <initializer_list>

class Lifeguard {
public:
  explicit Lifeguard(int) { puts("Lifeguard(int)"); }

  Lifeguard(std::initializer_list<int>)
  {
    puts("Lifeguard(std::initializer_list<int>)");
  }
};

int main()
{
  Lifeguard f{2};
  Lifeguard f2{2, 3};

  Lifeguard f3(2);
  Lifeguard f4({2, 3});
}