#include <memory>

struct Apple {
  Apple(int) {}
  void Fun() {}
};

void someMethod(Apple* m) {}

int main()
{
  std::unique_ptr<Apple> ptr1{std::make_unique<Apple>(2)};

  // use a Fun from Apple
  ptr1->Fun();

  // get a raw pointer back
  someMethod(ptr1.get());

  // move the resource
  std::unique_ptr<Apple> ptr2{std::move(ptr1)};

  // assign a new value
  ptr1.reset(new Apple{3});
  // better
  ptr1 = std::make_unique<Apple>(3);

  // clear the unique_ptr
  ptr1.reset();
}