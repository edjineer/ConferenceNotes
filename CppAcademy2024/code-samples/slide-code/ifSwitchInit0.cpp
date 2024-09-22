#include <mutex>

void SendUpdateNotificationEvent() {}
class Screen {};
Screen* screen{};

std::mutex gMutex;

void ChangeScreen(Screen& newScreen)
{
  if(std::lock_guard lock{gMutex};
     screen == &newScreen) {
    return;
  } else {
    screen = &newScreen;  // still in locked scope
  }

  // not part of locked scope
  SendUpdateNotificationEvent();
}

int main()
{
  Screen nscreen{};

  ChangeScreen(nscreen);
}