#include <cstdio>
#include <memory>
#include <utility>

class Apple {
  int mX;

public:
  Apple(int x)
  : mX{x}
  {
    printf("ctor %d\n", mX);
  }

  ~Apple() { printf("dtor: %d\n", mX); }

  void Print() const { printf("%d\n", mX); }
};

// #A The ownership of f is unclear
void Fun(Apple* f) { f->Print(); }

int main()
{
  auto f = new Apple{37};

  Fun(f);

  f->Print();
  delete f;  // #B Cleanup required
}