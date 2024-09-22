#include <cstdio>
#include <vector>

template<typename T, typename... Args>
void push_back(std::vector<T>& v, Args&&... vals)
{
  v.reserve(v.size() + sizeof...(vals));

  (v.push_back(std::forward<Args>(vals)), ...);
}

int main()
{
  std::vector v{2, 3, 4};
  const int   z = 5;

  push_back(v, z, 6, 7);
}