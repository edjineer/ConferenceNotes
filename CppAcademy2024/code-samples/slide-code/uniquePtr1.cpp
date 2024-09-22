#include <cstdio>
#include <memory>
#include <utility>

class Apple {
  int mX{};

public:
  explicit Apple(int x)
  : mX{x}
  {
    printf("ctor %d\n", mX);
  }

  ~Apple() { printf("dtor: %d\n", mX); }

  void Print() const { printf("%d\n", mX); }
};

void Fun(std::unique_ptr<Apple> f) { f->Print(); }

int main()
{
  auto f = std::make_unique<Apple>(37);

  Fun(std::move(f));
}