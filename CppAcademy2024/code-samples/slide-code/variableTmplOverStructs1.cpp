template<int N>
constexpr inline int test = N;

int x0 = test<0>;
int x1 = test<1>;

int main() {}
