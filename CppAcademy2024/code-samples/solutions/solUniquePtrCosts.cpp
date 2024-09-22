#include <memory>

#ifdef DOES_NOT_LINK
void bar(int* ptr);

// Takes ownership.
void baz(std::unique_ptr<int> ptr);

void foo(std::unique_ptr<int> ptr)
{
  if(*ptr > 42) {
    bar(ptr.get());
    *ptr = 42;
  }

  baz(std::move(ptr));
}
#endif

// Remove to avoid optimization
int main() {}