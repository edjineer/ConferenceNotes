#include <cstdio>

struct UInit {
  UInit() { puts("default"); }

  UInit(const UInit&) { puts("copy ctor"); }
};

int main()
{
  UInit a;
  UInit b(a);
  UInit c{a};
}