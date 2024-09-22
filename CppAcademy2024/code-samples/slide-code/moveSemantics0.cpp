#include <cstdio>

struct DynInt {
  int* mData{};

  DynInt(int v) : mData{new int{v}} {}

  ~DynInt() { delete mData; }

  DynInt(const DynInt& rhs) 
  : mData{new int{*rhs.mData}} {}

  DynInt(DynInt&& rhs)
  : mData{rhs.mData}  // Use std::exchange
  { rhs.mData = nullptr; }
};

struct Holder {
  DynInt mData;

  Holder(const DynInt& rhs) 
  : mData{rhs}
  { puts("Holder copy ctor"); }

  Holder(DynInt&& rhs) 
  : mData{static_cast<DynInt&&>(rhs)}
  { puts("Holder move ctor"); }
};

void Fun(Holder);

void Use() { Fun(DynInt{5}); }


void Fun(Holder) {}


int main() { Use(); }