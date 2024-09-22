// #A Helper to store a value at compile-time
template<class T, T v>
struct integral_constant {
  static constexpr T value = v;
};

// #B Aliases for clean TMP
using true_type  = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

// #C Base is_pointer template
template<class T>
struct is_pointer : false_type {};

// #D is_pointer specialization for T*
template<class T>
struct is_pointer<T*> : true_type {};

// #E Test it
static_assert(is_pointer<int*>::value);
static_assert(not is_pointer<int>::value);

int main() {}
