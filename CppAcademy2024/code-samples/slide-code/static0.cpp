#include <cstdio>
#include <cstring>

class Singleton {
public:
  static Singleton& Instance();

private:
  Singleton() = default;
};

Singleton& Singleton::Instance()
{
  static Singleton singleton;

  return singleton;
}

int main() { Singleton& s = Singleton::Instance(); }