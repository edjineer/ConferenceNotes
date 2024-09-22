#include <memory>

class Test {
public:
  ~Test() = default;
};

class West {};

int main()
{
  Test t0{};
  Test t1{std::move(t0)};

  West w0{};
  West w1{std::move(w0)};
}