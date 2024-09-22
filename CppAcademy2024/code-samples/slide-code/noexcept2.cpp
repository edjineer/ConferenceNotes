void Fun(int);

void Tick() noexcept;

struct Apple {
  int i;
  ~Apple() { Fun(i); }
};

void c(int i)
{
  Apple obj{i};  // #A Can be skipped

  Tick();

  obj.i = 4;
}

// delete for demo
void Fun(int) {}

void Tick() noexcept {}

// end delete

int main() {}
