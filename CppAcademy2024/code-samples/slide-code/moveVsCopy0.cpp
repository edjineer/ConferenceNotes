#include <cstdio>
#include <cstring>

void Copy(char** dst, char** src, size_t size)
{
  *dst = new char[size];
  memcpy(*dst, *src, size);
}

int main()
{
  char* ptr  = nullptr;
  char* data = new char[1'024]{'A'};

  Copy(&data, &ptr, 1'024);

  printf("%c %c\n", data[0], ptr[0]);
}