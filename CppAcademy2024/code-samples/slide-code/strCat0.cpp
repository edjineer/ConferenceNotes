#include <codecvt>
#include <locale>
#include <string>
#include <string_view>

using convert_t = std::codecvt_utf8<wchar_t>;
std::wstring_convert<convert_t, wchar_t> strconverter;

std::string to_string(std::wstring wstr) { return strconverter.to_bytes(wstr); }

std::wstring to_wstring(std::string str) { return strconverter.from_bytes(str); }

// Fake QString
class QString {
public:
  QString() = default;
  QString(std::wstring s)
  : mData{s}
  {}

  std::wstring toStdWString() const { return mData; }
  std::string  toStdString() const { return to_string(mData); }

private:
  std::wstring mData;
};

// #A Helper functions to convert everything into a std::string
auto Normalize(const std::string& t) { return t; }
auto Normalize(const QString& t) { return t.toStdString(); }
auto Normalize(const char* t) { return std::string_view{t}; }

// #B Catch all others and apply to_string
template<class T> auto Normalize(const T& t) { return std::to_string(t); }

template<typename T, typename... Ts> auto _StrCat(std::string& ret, const T& targ, const Ts&... vals)
{
  ret += Normalize(targ);
  if constexpr(sizeof...(vals) > 0) {
    _StrCat(ret, vals...);  // #C Do, as long as the pack has elements
  }
}

template<typename T, typename... Ts> auto StrCat(const T& targ, const Ts&... vals)
{
  std::string ret{Normalize(targ)};

  _StrCat(ret, vals...);  // #D Start the recursion to expand the pack

  return ret;
}

int main()
{
  QString qs(L"qhello");
  auto    s = StrCat("Hello", "C++", 20, qs);
  printf("%s\n", s.c_str());
}