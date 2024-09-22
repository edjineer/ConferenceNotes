#include <cstdio>
#include <utility>
class Base 
{
public:
    virtual ~Base() {}

    virtual void Fun() = 0;
};


class Derived : public Base
{
    int mX{};

public:  
    Derived(int x) : mX{x}
    {}

    int Get() const { return mX; }

    void Fun() override {}
};


int main()
{
    Derived f{std::move(Derived(2))};
}