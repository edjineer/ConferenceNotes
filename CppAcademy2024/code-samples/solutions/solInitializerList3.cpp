#include <cstdio>
#include <initializer_list>

struct UInit {
  UInit() { puts("default"); }

  UInit(const UInit&) { puts("copy ctor"); }

  UInit(const std::initializer_list<UInit>&) { puts("initializer list"); }
};

int main()
{
  UInit a;
  UInit b(a);  // copy ctor
  UInit c{a};  // copy ctor (init. list element) + initializer list!!!
}