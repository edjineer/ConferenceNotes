#include <cstdio>
#include <vector>

struct Lifeguard {
  Lifeguard() { puts("Lifeguard()"); }
  ~Lifeguard() { puts("~Lifeguard()"); }

  Lifeguard(int) { puts("Lifeguard(int)"); }

  Lifeguard(const Lifeguard&)
  {
    puts("Lifeguard(const Lifeguard&)");
  }
  Lifeguard& operator=(const Lifeguard&)
  {
    puts("Lifeguard& operator=(const Lifeguard&)");
    return *this;
  }

  Lifeguard(Lifeguard&&) noexcept
  {
    puts("Lifeguard(Lifeguard&&)");
  }
  Lifeguard& operator=(Lifeguard&&) noexcept
  {
    puts("Lifeguard& operator=(Lifeguard&&)");
    return *this;
  }
};

int main()
{  // #A Avoid seeing the realloc's
  std::vector<Lifeguard> v{};
  v.reserve(5);

  puts("- push_back");

  // #B Using push_back with a temporary object.
  v.push_back(Lifeguard{3});

  puts("- emplace_back");

  // #C Using emplace_back with a temporary  object.
  v.emplace_back(Lifeguard{3});

  puts("- emplace_back");

  // #D Using emplace_back to create a new object.
  v.emplace_back(3);

  puts("-------");
}