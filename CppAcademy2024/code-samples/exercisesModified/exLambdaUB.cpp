#include <iostream>
#include <string>

using namespace std::string_literals;

auto makeLambda()
{
  const auto val{"created on the stack"s};
  return [&] { return val; };
}

int main()
{
  const auto bad = makeLambda();
  std::cout << bad() << '\n';
  //Problem = Passing back by reference, and the scope will destroy it
  //Fix it by passing by value 
}