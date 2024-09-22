// requires -Wpedantic or -Wvla

#include <algorithm>
#include <array>
#include <cstdio>
#include <vector>

// Fake of OS headers. The body is provided to make the code link.
namespace Linux {
  void InitLeds() {}
}  // namespace Linux

namespace Apple {
  void InitLeds() {}
}  // namespace Apple

namespace Windows {
  void InitLeds() {}
}  // namespace Windows
// Fake end

enum class HostType { MacOS, Linux, Windows };

#define PI 3.14

class Point {
  double mX{};
  double mY{};

public:
  Point(double x, double y) noexcept
  : mX{x}
  , mY{y}
  {}

  double GetX() const noexcept { return mX; }
  double GetY() const noexcept { return mY; }

  void SetX(double x) noexcept { mX = x; }
  void SetY(double y) noexcept { mY = y; }
};

struct Config {
  bool     debug;
  HostType hostType;
  size_t   hLines;
  size_t   vLines;
  double   mainAngle;
  Point    mainPosition;
  // ...
};

const Config cfg{
#ifdef DEBUG
  true
#else
  false
#endif
  ,
#ifdef __linux__
  HostType::Linux
#elif defined(__APPLE__)
  HostType::MacOS
#elif defined(_WIN32) || defined(WIN32)
  HostType::Windows
#endif
  ,
  640,
  480,
  0.4 * 2 * PI,
  Point{3, 4}};

bool good_angle(const int angle)
{
  static const std::vector allowedAngles{-90, -45, 0, 45, 90};

  return std::find(begin(allowedAngles), end(allowedAngles), angle) != allowedAngles.end();
}

const std::array<double, 5> positions{
  0.0 * 2 * PI,
  0.1 * 2 * PI,
  0.2 * 2 * PI,
  0.3 * 2 * PI,
  0.4 * 2 * PI,
};

bool CheckIfMainAngleIsSupported()
{
  for(const auto& e : positions) {
    if(e == cfg.mainAngle) { return true; }
  }

  return false;
}

bool Init()
{
#ifdef __linux__
  Linux::InitLeds();
#elif defined(__APPLE__)
  Apple::InitLeds();
#elif defined(_WIN32) || defined(WIN32)
  Windows::InitLeds();
#endif

  return CheckIfMainAngleIsSupported();
}

int main()
{
#if !(defined(_WIN32) || defined(WIN32))
  // Doesn't compile under Windows, try to make it work if you're under Windows.
  char displayBuffer[cfg.hLines][cfg.vLines];
#endif

  if(cfg.debug) { puts("Debugging on"); }

  if(not Init()) { return 1; }

  // programm starts...
}