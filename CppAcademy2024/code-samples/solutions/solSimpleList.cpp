#include <cstdio>

template<typename T>
struct list_entry {
  T           data;
  list_entry* next;

  void add(list_entry& item) { next = &item; }
};

struct sentinel_t {};

template<typename T>
struct list_iterator {
  list_entry<T>* list{};

  auto& operator++()
  {
    list = list->next;

    return *this;
  }

  bool operator!=(sentinel_t) { return list; }

  T& operator*() { return list->data; }
};

template<typename T>
auto begin(list_entry<T>& list)
{
  return list_iterator<T>{&list};
}

template<typename T>
auto end(list_entry<T>&)
{
  return sentinel_t{};
}

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

  puts("------");

  for(auto& e : a) { printf("%d\n", e); }
}