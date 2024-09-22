template<typename T,
         typename... Ts  // #A Variadic template
         >
constexpr auto
min(const T& x,
    const T& y,
    const Ts&... vals)  // #B Parameter pack
{
  const auto m = x < y ? x : y;
  if constexpr(
    // #C size of a pack
    sizeof...(vals) > 0) {

    // #D Expand the pack
    return min(m, vals...);

  } else {
    return m;
  }
}

static_assert(min(3, 2) == 2);
static_assert(min(3, 2, 3, 4, 5) == 2);

int main() {}
