auto lambdaVariable = [](auto x, auto y) {
  return x + y;
};

int main()
{
  const double res = lambdaVariable(2.0, 3.0);

  return lambdaVariable(2, 3);
}