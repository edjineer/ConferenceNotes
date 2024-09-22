#include <cstdio>
#include <cstring>

void Move(char** dst, char** src)
{
  *dst = *src;
  *src = nullptr;
}

int main()
{
  char* ptr  = nullptr;
  char* data = new char[1'024]{'A'};

  printf("%d\n", (nullptr == data));

  Move(&ptr, &data);

  printf("%c %d\n", ptr[0], (nullptr == data));
}