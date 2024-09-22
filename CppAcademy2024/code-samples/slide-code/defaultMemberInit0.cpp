#include <string>
#include <vector>

class DInit {
  int              i{5};
  std::vector<int> v{2, 3, 4};
  std::string      s{"Hello"};

public:
  DInit() = default;

  DInit(const std::vector<int>& _v)
  : v{_v}
  {}

  DInit(int _i)
  : i{_i}
  {}

  DInit(const std::string& _s)
  : s{_s}
  {}
};

int main() { DInit a{}; }