#include <cstdio>

int main()
{
class Base 
{
public:
    virtual ~Base() = default;
    Base(const Base& ) = default;
    Base(      Base&&) = default;
    
    Base& operator=(const Base& ) = default;
    Base& operator=(      Base&&) = default;

    virtual void Fun() = 0;
};

}