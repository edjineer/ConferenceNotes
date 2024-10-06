#include <cstdio>

template<typename T, typename ... Ts >
 constexpr auto templateSum(const T& x, const Ts&... vals)
{
  if constexpr(sizeof...(vals) > 0)
  {
    return x + templateSum(vals...);
  }
  else
  {
    return x; 
  }
}



int main() 
{
    auto sum1 = templateSum(1,3,5);
    printf("%d\n", sum1);
    auto sum2 = templateSum(4, 6.5, 10.0, true, 4);
    printf("%f\n", sum2);
}