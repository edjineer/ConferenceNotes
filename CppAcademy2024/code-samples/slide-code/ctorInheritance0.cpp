class Base {
protected:
  Base(int x)
  : mX{x}
  {}

private:
  int mX;
};

class Derived : public Base {
  using Base::Base;

public:
  Derived(double d)
  : Derived{static_cast<int>(d)}
  {}
};

int main()
{
  Derived d{2.4};
}