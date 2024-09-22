#include <cstdio>
#include <memory>

template<typename F, typename S>
struct pair {
  F first;
  S second;
};

template<typename F, typename S>
inline auto make_pair(F&& f, S&& s)
{
  // Production code should use std::remove_cvref_t
  return pair<F, S>{std::forward<F>(f),
                    std::forward<S>(s)};
}

// Production code should use std::remove_cvref_t
template<typename F, typename S>
pair(F&& f, S&& s) -> pair<F, S>;

struct Lifeguard {
  Lifeguard() { puts("ctor"); }
  ~Lifeguard() { puts("dtor"); }
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

auto UseA()
{
  auto p{make_pair(3, Lifeguard{})};

  return p;
}

auto UseB()
{
  pair p{3, Lifeguard{}};

  return p;
}

int main()
{
  UseA();
  puts("-----");
  UseB();
}