#include <cstdio>
#include <cstdlib>
#include <memory>

void* operator new(std::size_t n)
{
  printf("new: %zd\n", n);

  return std::malloc(n);
}

void* operator new(std::size_t n, std::align_val_t align)
{
  printf("new: %zd\n", n);

  return std::malloc(n);
}

void operator delete(void* p) throw()
{
  if(nullptr != p) { std::free(p); }
}

void mydelete(int* p)
{
  delete p;
}

struct TenInts {
  int ar[10];
};

int main()
{
  printf("sizeof(int): %zd\n", sizeof(int));
  printf("sizeof(void*): %zd\n", sizeof(void*));

  {
    puts("std::shared_ptr<int> p(new int(3));");
    std::shared_ptr<int> p(new int(3));
    std::shared_ptr<int> p2 = p;
  }

  puts("-------");

  {
    puts("std::shared_ptr<int> p{std::make_shared<int>(2)};");
    std::shared_ptr<int> p{std::make_shared<int>(2)};
    std::shared_ptr<int> p2 = p;
  }

  puts("-------");

  {
    puts("std::shared_ptr<int> p(new int(3), &mydelete);");
    std::shared_ptr<int> p(new int(3), &mydelete);
    std::shared_ptr<int> p2 = p;
  }

  puts("-------");

  {
    puts("std::shared_ptr<TenInts> p(new TenInts{});");
    std::shared_ptr<TenInts> p(new TenInts{});
    std::shared_ptr<TenInts> p2 = p;
  }

  puts("-------");

  {
    puts("std::shared_ptr<TenInts> p(std::make_shared<TenInts>());");
    std::shared_ptr<TenInts> p(std::make_shared<TenInts>());
    std::shared_ptr<TenInts> p2 = p;
  }
}

// https://godbolt.org/z/eeeoj7
// Possible output:
// sizeof(int): 4
// sizeof(void*): 8
// std::shared_ptr<int> p(new int(3));
// new: 4
// new: 24
// -------
// std::shared_ptr<int> p{std::make_shared<int>(2)};
// new: 24
// -------
// std::shared_ptr<int> p(new int(3), &mydelete);
// new: 4
// new: 32
// -------
// std::shared_ptr<TenInts> p(new TenInts{});
// new: 40
// new: 24
// -------
// std::shared_ptr<TenInts> p(std::make_shared<TenInts>());
// new: 56