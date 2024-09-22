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

template<typename T>
requires(has_leisure_time<T> and has_fun<T> and
         not has_hobby<T>) 
void Fun(T) { puts("fun only"); }

template<typename T>
requires(has_leisure_time<T> and has_fun<T> and 
           has_hobby<T>) 
void Fun(T) { puts("fun and hobby"); }


int main()
{
  A a{};
  B b{};

  Fun(a);
  Fun(b);
}