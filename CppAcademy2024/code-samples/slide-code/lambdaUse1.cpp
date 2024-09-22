#include <cstdio>
#include <string>

using namespace std::string_literals;

const std::string globalName{"world"s};

void Fun(int e)
{
  const std::string name{[&] {
    switch(e) {
      case 0: return "void"s;
      case 1: return globalName;
      case 2: return "bool"s;
      default: return ""s;
    }
  }()};

  printf("name: %s\n", name.c_str());
}

int main() { Fun(false); }