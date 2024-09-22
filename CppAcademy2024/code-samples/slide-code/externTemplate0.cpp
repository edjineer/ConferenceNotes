template<typename T>
struct S {
  T Fun() { return data; }

  T data;
};

extern template struct S<int>;

int main() {}
