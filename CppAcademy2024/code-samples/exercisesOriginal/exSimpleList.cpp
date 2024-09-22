#include <cstdio>

template<typename T>
struct list_entry {
  T           data;
  list_entry* next;

  void add(list_entry& item) { next = &item; }
};

int main()
{
  using list = list_entry<int>;

  list a{3};

  list b{4};
  a.add(b);

  list c{5};
  b.add(c);

  list* iter = &a;
  while(iter) {
    printf("%d\n", iter->data);
    iter = iter->next;
  }
}