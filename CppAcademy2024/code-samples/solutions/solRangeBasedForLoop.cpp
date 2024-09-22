#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

auto square(int& i)
{
  i *= i;
}

void DumpContainer(const std::vector<int>& cont)
{
  for(const int i : cont) { std::cout << i << " "; }

  std::cout << '\n';
}

void Init(std::vector<int>& cont)
{
#if 1
  int inc = 0;
  for(int& i : cont) { i = ++inc; }
#else
  std::iota(cont.begin(), cont.end(), 1);
#endif

  DumpContainer(cont);
}

void WithForLoop(std::vector<int> cont)
{
  for(int& i : cont) { i = (i * i); }

  DumpContainer(cont);
}

void WithForEach(std::vector<int> cont)
{
  std::for_each(cont.begin(), cont.end(), square);

  DumpContainer(cont);
}

int main()
{
  std::vector<int> values(10);

  Init(values);

  WithForLoop(values);

  WithForEach(values);
}