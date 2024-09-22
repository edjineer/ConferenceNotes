// #A As seen before
template<class T, T v>
struct integral_constant {
  static constexpr T value = v;
};

using true_type  = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

template<class T>
struct is_pointer : false_type {};

template<class T>
struct is_pointer<T*> : true_type {};

// #B A variable template to access ::value
template<typename T>
constexpr inline auto is_pointer_v =
  is_pointer<T>::value;

// #C is_pointer_v looks cleaner than ::value
static_assert(is_pointer_v<int*>);
static_assert(not is_pointer_v<int>);

int main() {}
