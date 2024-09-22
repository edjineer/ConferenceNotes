#include <string>

int main()
{
  std::string u;                       // #A default
  std::string v = std::string();       // #B value
  std::string w("C++");                // #C direct
  std::string x    = "C++";            // #D copy
  char        y[4] = {'C', '+', '+'};  // #E aggregate
  char&       z    = y[0];             // #F reference
}