#include <cstdio>
#include <vector>

struct Lifeguard {
  Lifeguard() { puts("ctor"); }
  Lifeguard(const Lifeguard&) { puts("copy ctor"); }
  Lifeguard(Lifeguard&&) { puts("move ctor"); }
  Lifeguard& operator=(const Lifeguard&)
  {
    puts("copy assign");
    return *this;
  }
  Lifeguard& operator=(Lifeguard&&)
  {
    puts("move assign");
    return *this;
  }
};

int main()
{
  std::vector<Lifeguard> v{};

  v.push_back(Lifeguard{});

  puts("second element");
  v.push_back(Lifeguard{});
}