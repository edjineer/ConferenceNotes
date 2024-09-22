#include <cstdio>

template<typename T>
concept has_leisure_time = requires(T t)
{ t.hasLeisureTime(); };

template<typename T>
concept has_fun = requires(T t) { t.hasFun(); };

template<typename T>
concept has_hobby = requires(T t) { t.hasHobby(); };

struct A {
  void hasLeisureTime() {}
  void hasFun() {}
};

struct B {
  void hasLeisureTime() {}
  void hasFun() {}
  void hasHobby() {}
};

void Fun(has_leisure_time auto t) {
  constexpr bool hasHobby = requires { t.hasHobby(); };
  constexpr bool hasFun   = requires { t.hasFun(); };

  if constexpr(hasFun and not hasHobby) {
    puts("fun only");
  } else if constexpr(hasFun and hasHobby) {
    puts("fun and hobby");
  }
}


int main()
{
  A a{};
  B b{};

  Fun(a);
  Fun(b);
}