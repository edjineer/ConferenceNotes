#include <cstdio>
#include <new>  // for placement new

#define __no_init

struct guard {
  bool x;
  int  first_byte;

  guard& operator=(bool b)
  {
    x = b;
    return *this;
  }
};

bool __atomic__load(int) { return true; }

bool __cxa_guard_acquire(int) { return true; }
void __cxa_guard_release(int) {}

class Singleton {
public:
  static Singleton& Instance();

private:
  Singleton();
  ~Singleton();
};

Singleton& Singleton::Instance()
{
  static int  __compiler_computed;
  static char singleton[sizeof(Singleton)];

  if(!__compiler_computed) {
    if(__cxa_guard_acquire(__compiler_computed)) {
      new(&singleton) Singleton;
      __compiler_computed = true;
      __cxa_guard_release(__compiler_computed);
    }
  }

  return *reinterpret_cast<Singleton*>(&singleton);
}

Singleton::Singleton() { puts("ctor"); }

Singleton::~Singleton() { puts("dtor"); }

int main() { Singleton& x = Singleton::Instance(); }