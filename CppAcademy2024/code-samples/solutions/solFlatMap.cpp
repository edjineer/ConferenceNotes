#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>

int main()
{
  std::map<std::string, int> myMap{{"Dijkstra", 1972}, {"Scott", 1976}, {"Wilkes", 1967}, {"Hamming", 1968}};
  std::vector<std::pair<std::string, int>> myFlatMap{
    {"Dijkstra", 1972}, {"Scott", 1976}, {"Wilkes", 1967}, {"Hamming", 1968}};

  std::sort(
    std::begin(myFlatMap), std::end(myFlatMap), [](const auto& fir, const auto& sec) { return fir.first < sec.first; });

  for(const auto& [k, v] : myMap) { std::cout << '{' << k << ',' << v << '}'; }

  std::cout << '\n';

  for(const auto& [k, v] : myFlatMap) { std::cout << '{' << k << ',' << v << '}'; }

  std::cout << "\n\n";

  std::cout << "myMap[Scott]: " << myMap["Scott"] << '\n';

  auto iter = std::lower_bound(
    std::begin(myFlatMap), std::end(myFlatMap), std::pair<std::string, int>("Scott", std::numeric_limits<int>::min()));
  std::cout << "myFlatMap[Scott]: " << iter->second << '\n';

  auto iter2 =
    std::find_if(std::begin(myFlatMap), std::end(myFlatMap), [](const auto& pair) { return pair.first == "Scott"; });

  std::cout << "myFlatMap[Scott]: " << iter2->second << '\n';
}