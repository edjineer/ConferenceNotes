#include <vector>

int main()
{
  std::vector<std::vector<int>> v{};
#if FAILS_COMPILE
  v.push_back(2 << 4);
  v.emplace_back(2 << 4);

#endif
}