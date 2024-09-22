#include <cstdio>
#include <string>

class TextFormatter {
  std::string mValue{};

public:
  explicit TextFormatter(std::string val)
  : mValue{val}
  {}

  virtual ~TextFormatter() = default;

  virtual bool InsertNewLine() const { return true; }
};

class RawFormatter : public TextFormatter {
  int mData{};

public:
  // #A Get ctor's of base - class
  using TextFormatter::TextFormatter;

  bool InsertNewLine() const override { return false; }
};

RawFormatter braces{"Hello"};

int main() {}
