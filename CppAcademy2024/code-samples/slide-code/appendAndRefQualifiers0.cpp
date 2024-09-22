#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

class string {
  size_t                  mLen{};
  std::unique_ptr<char[]> mData{};

  void Concat(const char* s);

public:
  string(const char* data);
  string(const string& rhs);
  string& operator=(const string& rhs);
  string(string&& rhs);
  string& operator=(string&& rhs);
  char*   c_str() const { return mData.get(); }

  string& append(const char* s)
  {
    Concat(s);
    return *this;
  }
};

string::string(const string& rhs)
: mLen{rhs.mLen}
, mData{std::make_unique<char[]>(mLen)}
{
  std::copy_n(rhs.mData.get(), mLen, mData.get());
}

string& string::operator=(const string& rhs)
{
  if(&rhs != this) {
    mLen  = rhs.mLen;
    mData = std::make_unique<char[]>(mLen);
    std::copy_n(rhs.mData.get(), mLen, mData.get());
  }

  return *this;
}

string::string(string&& rhs)
: mLen{std::exchange(rhs.mLen, 0)}
, mData{std::exchange(rhs.mData, nullptr)}
{}

string& string::operator=(string&& rhs)
{
  if(&rhs != this) {
    mLen  = std::exchange(rhs.mLen, mLen);
    mData = std::exchange(rhs.mData, std::move(mData));
  }

  return *this;
}

void string::Concat(const char* s)
{
  const size_t sLen =
    std::char_traits<char>::length(s);
  const size_t newLen = mLen + sLen + 1;

  auto old = std::exchange(
    mData, std::make_unique<char[]>(newLen));
  std::copy_n(old.get(), mLen, mData.get());

  std::copy_n(s, sLen, mData.get() + mLen);

  mLen = newLen;
}

string::string(const char* data)
: mLen{std::char_traits<char>::length(data)}
{
  mData.reset(new char[mLen]);
  std::copy_n(data, mLen, mData.get());
}

int main()
{
  string s{"Hello"};
  s.append(", world!");

  std::cout << s.c_str();
}