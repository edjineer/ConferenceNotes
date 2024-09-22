#include <iostream>

class Widget {
  static int getHeight(int w) { return w * 3 / 4; }

  int  width;
  int  height;
  bool frame;
  bool visible;

public:
  Widget()
  : width{640}
  , height{480}
  , frame{false}
  , visible{true}
  {}

  explicit Widget(int w)
  : width{w}
  , height{getHeight(w)}
  , frame{false}
  , visible{true}
  {}

  Widget(int w, int h)
  : width{w}
  , height{h}
  , frame{false}
  , visible{true}
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