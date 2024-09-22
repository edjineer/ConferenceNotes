template<int N>
struct test {
  static constexpr int value = N;
};

int x0 = test<0>::value;
int x1 = test<1>::value;

int main() {}
