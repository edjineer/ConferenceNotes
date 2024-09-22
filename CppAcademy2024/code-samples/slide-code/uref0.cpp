#include <cstdio>

struct Apple
{
};

template<typename T>
struct Class {};

Apple Fun() { return {}; }

Apple&& apple1 = Fun();  // rvalue ref
auto&&  apple2 = Fun(); // forwarding ref

void Fun(Apple&& f);     // rvalue ref

template<typename T>
void Fun(Class<T>&& f);  // rvalue ref

template<typename T>
void Fun(T&& f);         // forwarding ref


int main() { }