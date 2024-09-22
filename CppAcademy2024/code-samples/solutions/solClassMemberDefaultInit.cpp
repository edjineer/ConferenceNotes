#include <iostream>

class Widget {
  static int getHeight(int w) { return w * 3 / 4; }

  int  width{640};
  int  height{480};
  bool frame{false};
  bool visible{true};

public:
  Widget() = default;

  explicit Widget(int w)
  : width{w}
  , height{getHeight(w)}
  {}

  Widget(int w, int h)
  : width{w}
  , height{h}
  {}

  void show()
  {
    std::cout << std::boolalpha << width << "x" << height << ", frame: " << frame << ", visible: " << visible << '\n';
  }
};

int main()
{
  Widget wVGA{};
  Widget wSVGA{800};
  Widget wHD{1280, 720};

  wVGA.show();
  wSVGA.show();
  wHD.show();
}