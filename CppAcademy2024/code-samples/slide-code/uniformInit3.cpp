#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <vector>

int main()
{
  // Classic C++

  const int arr[]{3, 4, 27, 22, 9};

  std::vector<int> v;
  for(int i = 0; i < 5; ++i) { v.push_back(arr[i]); }

  std::set<int> s;
  for(int i = 0; i < 5; ++i) { s.insert(arr[i]); }

  std::map<int, std::string> m;
  m[0] = "null";
  m[1] = "first";
  m[2] = "second";

  std::vector<int> v2;
  v2.push_back(20);
  v2.push_back(30);
  v2.push_back(40);
  v2.push_back(50);
}