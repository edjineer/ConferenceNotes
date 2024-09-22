struct B {
  ~B();
};

void f();

void g() noexcept
{
  B b1{};

  f();

  B b2{};
}

// delete for demo
void f() {}

B::~B() {}
// end delete

int main() {}
