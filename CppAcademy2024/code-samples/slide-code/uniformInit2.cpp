#include <cstdio>

class Lifeguard {
public:
  Lifeguard() { puts("Lifeguard()"); }
  Lifeguard(int) { puts("Lifeguard(int)"); }
  Lifeguard(const Lifeguard&)
  {
    puts("Lifeguard(Lifeguard&)");
  }
};

int main()
{
  Lifeguard a(3);
  Lifeguard b();
  Lifeguard c{3};
  Lifeguard d{};
}