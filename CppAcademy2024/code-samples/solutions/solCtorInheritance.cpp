class Base {
  int mX{};

public:
  explicit Base(int x)
  : mX{x}
  {}
};

class DerivedPublic : public Base {
  using Base::Base;
};

class DerivedProtected : protected Base {
  using Base::Base;
};

class DerivedPrivate : private Base {
  using Base::Base;
};

int main()
{
  Base             b{2};
  DerivedPublic    d1{3};
  DerivedProtected d2{4};
  DerivedPrivate   d3{5};
}