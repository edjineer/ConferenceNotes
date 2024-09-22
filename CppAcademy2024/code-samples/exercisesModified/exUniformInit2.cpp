#include <initializer_list> 
#include <cstdio>

void List(std::initializer_list<int> input)
{
    for(int i{0}; i < input.size(); ++i) 
    { 
        printf("%d\n", input[i]); # Wrong, not allowed
    }
}

int main() 
{
    List({2, 3, 4, 5});
}