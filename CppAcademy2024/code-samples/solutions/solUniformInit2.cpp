#include <cstdio>
#include <initializer_list>

void List(std::initializer_list<int> list)
{
  for(const int* i{list.begin()}; i != list.end(); ++i) { printf("%d\n", *i); }
}

int main()
{
  List({2, 3, 4, 5});
}