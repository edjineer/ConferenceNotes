#include <cstdio>

struct Apple {
  int  x;
  char c;
};

class Orange {
  int  mX;
  char mC;

public:
  Orange(int x, char c)
  : mX(x)
  , mC(c)
  {}
};

int main()
{
  Apple f;
  f.x = 3;
  f.c = 250;

  Orange b(2, 'x');

  int x = 4;

  for(int i = 0; i < 10; ++i) { printf("i=%d\n", i); }
}