#include <cstdio>
#include <mutex>

std::mutex gMutex;

template<typename T>
void DoLocked(T&& action)
{
  std::lock_guard _{gMutex};

  action();
}

int main()
{
  DoLocked([] { puts("Hello"); });
}