#include <memory>

#ifdef UNCOMMENT_AS_IT_DOESNT_LINK
void bar(int* ptr);

// Takes ownership
void baz(int* ptr);

void foo(int* ptr)
{
  if(*ptr > 42) {
    bar(ptr);
    *ptr = 42;
  }

  baz(ptr);
}
#endif

// Remove to avoid optimization
int main() {}