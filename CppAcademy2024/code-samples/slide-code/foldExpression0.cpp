template<typename... Ts>
constexpr auto avg(const Ts&... vals)
{
  return (vals + ...) / sizeof...(vals);
}

static_assert(avg(2, 3, 4) == 3);

int main() {}