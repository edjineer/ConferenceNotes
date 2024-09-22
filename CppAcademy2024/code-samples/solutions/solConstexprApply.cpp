// requires -Wpedantic or -Wvla

#include <algorithm>
#include <array>
#include <cstdio>

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

inline constexpr auto PI{3.14};

constexpr bool IsDebug()
{
#ifdef DEBUG
  return true;
#else
  return false;
#endif
}

class Point {
  double mX{};
  double mY{};

public:
  constexpr Point(double x, double y) noexcept
  : mX{x}
  , mY{y}
  {}

  constexpr double GetX() const noexcept { return mX; }
  constexpr double GetY() const noexcept { return mY; }

  constexpr void SetX(double x) noexcept { mX = x; }
  constexpr void SetY(double y) noexcept { mY = y; }
};

constexpr double calcPosition(double a)
{
  return a * 2 * PI;
}

struct Config {
  bool     debug;
  HostType hostType;
  size_t   hLines;
  size_t   vLines;
  double   mainAngle;
  Point    mainPosition;
  // ...
};

constexpr Config cfg{IsDebug(),
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
                     calcPosition(0.4),
                     Point{3, 4}};

bool good_angle(const int angle)
{
  static constexpr std::array allowedAngles{-90, -45, 0, 45, 90};

  return std::find(begin(allowedAngles), end(allowedAngles), angle) != allowedAngles.end();
}

constexpr std::array positions{
  calcPosition(0.0),
  calcPosition(0.1),
  calcPosition(0.2),
  calcPosition(0.3),
  calcPosition(0.4),
};

constexpr bool CheckIfMainAngleIsSupported()
{
  for(const auto& e : positions) {
    if(e == cfg.mainAngle) { return true; }
  }

  return false;
}

void Init()
{
  if constexpr(HostType::Linux == cfg.hostType) {
    Linux::InitLeds();
  } else if constexpr(HostType::MacOS == cfg.hostType) {
    Apple::InitLeds();
  } else if constexpr(HostType::Windows == cfg.hostType) {
    Windows::InitLeds();
  }

  static_assert(CheckIfMainAngleIsSupported());
}

int main()
{
  if constexpr(cfg.debug) { puts("Debugging on"); }

  char displayBuffer[cfg.hLines][cfg.vLines]{};

  Init();

  // programm starts...
}