#include <algorithm>
#include <cstdio>
#include <vector>

void Use(const int threshold)
{
  std::vector v{2, 3, 4, 5, 6, 7};

  std::for_each(v.begin(), v.end(), [threshold](int& e) {
    if(e < threshold) { e *= 2; }
  });

  std::for_each(v.begin(), v.end(), [](const int e) { printf("%d ", e); });
}

int main()
{
  Use(5);
}