#include <cstdio>
#include <string>

int main()
{
  std::string fun{};

  auto a = [=] { printf("%s\n", fun.c_str()); };

  auto b = [=] {};

  auto c = [fun] { printf("%s\n", fun.c_str()); };

  auto d = [fun] {};

  auto e = [&fun] { printf("%s\n", fun.c_str()); };

  auto f = [&fun] {};
}