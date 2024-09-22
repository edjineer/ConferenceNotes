#include <cstdio>
#include <utility>

class Apple {};

void fun(const Apple&) { puts("lvalue"); }

void fun(Apple&&) { puts("rvalue"); }

template<typename T>
void f(T&& t)
{
  fun(t);
}

template<typename T>
void g(T&& t)
{
  fun(std::forward<T>(t));
}

template<typename T>
void h(T&& t)
{
  fun(std::move(t));
}

int main()
{
  Apple b;

  f(b);
  g(b);
  h(b);

  puts("----");

  f(Apple{});
  g(Apple{});
  h(Apple{});
}