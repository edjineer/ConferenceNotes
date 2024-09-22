#include <cstdio>

auto lambdaVariable = [](int x, int y) {
  return x + y;
};

auto LambdaAsReturnObject()
{
  return [](int x, int y) { return x + y; };
}

template<typename T>
void LambdaAsArgument(T&& lambda)
{
  lambda();
}

int main()
{
  const int a = lambdaVariable(2, 3);

  const auto lr = LambdaAsReturnObject();
  const int  b  = lr(2, 3);

  LambdaAsArgument([] { puts("Hello, world!"); });
}