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

void Fun(std::shared_ptr<Apple> f)
{
  printf("count: %ld\n", f.use_count());
  f->Print();
}

int main()
{
  auto f = std::make_shared<Apple>(37);
  printf("count: %ld\n", f.use_count());

  Fun(f);
  printf("count: %ld\n", f.use_count());

  f->Print();
}