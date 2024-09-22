#include <cstdio>
#include <memory>

int main()
{
  using uinque_ptr_with_fclose = std::unique_ptr<FILE, decltype(&fclose)>;
  printf("%zd\n", sizeof(uinque_ptr_with_fclose));
  static_assert(sizeof(uinque_ptr_with_fclose) == sizeof(void*) * 2, "Size is not the expected");

  auto p = std::unique_ptr<FILE, decltype(&fclose)>{fopen("SomeFile.txt", "r"), &fclose};
}