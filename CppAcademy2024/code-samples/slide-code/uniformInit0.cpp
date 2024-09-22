#include <cstdio>

class Apple {
public:
  Apple() = default;
};

int main()
{
  Apple a;
  Apple b = a;
  b       = a;
}