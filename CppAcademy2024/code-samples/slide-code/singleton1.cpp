#include <cstdio>
#include <new>  // for placement new

#define __no_init

class Singleton {
public:
  static Singleton& Instance();

private:
  Singleton();
  ~Singleton();
};

Singleton& Singleton::Instance()
{
  static bool __compiler_computed;
  static char singleton[sizeof(Singleton)];

  if(!__compiler_computed) {
    new(&singleton) Singleton;
    __compiler_computed = true;
  }

  return *reinterpret_cast<Singleton*>(&singleton);
}

Singleton::Singleton() { puts("ctor"); }

Singleton::~Singleton() { puts("dtor"); }

int main() { Singleton& x = Singleton::Instance(); }