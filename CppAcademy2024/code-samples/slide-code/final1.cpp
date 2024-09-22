#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <span>

using namespace std;
namespace gsl {
  template<typename T, typename U>
  auto narrow_cast(const U& u)
  {
    return static_cast<T>(u);
  }
}  // namespace gsl

int Open() { return 0; }
int read(int fd, char* buffer, size_t bufLen)
{
  return 0;
}
int close(int fd) { return 0; }

size_t ReadData(span<char> buffer)
{
  int fd = Open(/*some well known file*/);

  if(-1 == fd) { return 0; }

  const auto len =
    read(fd, buffer.data(), buffer.size());

  if(-1 == len) { return 0; }

  ftruncate(fd, len);

  close(fd);

  return gsl::narrow_cast<size_t>(len);
}

int main() {}
