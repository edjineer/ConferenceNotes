#include <tuple>
#include <utility>

// This class contains some information of a type.
template<typename>
class trait {};

// Helper template mapping an index to a type.
template<template <int> class TypeMap, int N>
struct get_type_traits;

template<int> struct type_map;
template<> struct type_map<0> { using type = int; };
template<> struct type_map<1> { using type = float; };

template <template <int> class TypeMap, int N>
struct get_type_traits {
private:
  template<int... I>
  static auto impl(std::integer_sequence<int, I...>) {
    return std::make_tuple(
            trait<typename TypeMap<I>::type>{}...);
  }

public:
  using type = decltype(
          impl(std::make_integer_sequence<int, N>{}));
};

// Should be 'std::tuple<trait<int>, trait<float>>'.
using type_traits = get_type_traits<type_map, 2>::type;

int main() {}
