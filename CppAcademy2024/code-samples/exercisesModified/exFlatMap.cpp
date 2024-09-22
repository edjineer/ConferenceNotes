#include <iostream>
#include <map>
#include <string>

int main()
{
  std::map<std::string, int> myMap{{"Dijkstra", 1972}, {"Scott", 1976}, {"Wilkes", 1967}, {"Hamming", 1968}};
  // your flat map

  for(const auto& [k, v] : myMap) { std::cout << '{' << k << ',' << v << '}'; }
  std::cout << '\n';

  // iterate over your-flat-map like the std::map

  std::cout << "myMap[Scott]: " << myMap["Scott"] << '\n';

  // get the value for a key in your-flat-map like the std::map
}