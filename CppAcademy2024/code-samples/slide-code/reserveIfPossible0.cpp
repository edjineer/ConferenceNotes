#include <vector>

int AskForUserInput() { return 2; }

auto GetUserInput(const int numValues)
{
  std::vector<int> v{};

  for(int i = 0; i < numValues; ++i) {
    v.push_back(AskForUserInput());
  }

  return v;
}

int main() { auto input = GetUserInput(5); }