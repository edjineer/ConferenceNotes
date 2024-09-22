#include <cstddef>
#include <utility>

template<typename T>
struct ctrl_blk_base {
  // /* type-erased deleter */ deleter;
  size_t shared_ref_count_;
  size_t weak_ref_count_;
};

template<typename T>
struct ctrl_blk_with_storage : ctrl_blk_base<T> {
  template<typename... Args>
  explicit ctrl_blk_with_storage(Args&&... vals)
  : ctrl_blk_base<T>()
  , in_place_(std::forward<Args>(vals)...)
  {}

  T* get() { return &in_place_; }

  T in_place_;
};

template<typename T>
struct shared_ptr {
  shared_ptr(T* t)
  : shared_ptr(new ctrl_blk_base<T>(), t)
  {}

  T* get() const { return t_; }

  ~shared_ptr()
  {
    // if(ctrl_blk_) { ctrl_blk_->release_shared(); }
  }

private:
  shared_ptr(ctrl_blk_with_storage<T>* cb)
  : shared_ptr(cb, cb->get())
  {}

  shared_ptr(ctrl_blk_base<T>* cb, T* t)
  : ctrl_blk_(cb)
  , t_(t)
  {}

  ctrl_blk_base<T>* ctrl_blk_;
  T*                t_;

  template<typename U, typename... Args>
  friend shared_ptr<U> make_shared(Args&&... vals);
};

template<typename T, typename... Args>
shared_ptr<T> make_shared(Args&&... vals)
{
  return shared_ptr<T>(new ctrl_blk_with_storage<T>(
    std::forward<Args>(vals)...));
}

int main()
{
  struct S {
    S(int, int) {}
  };

  auto p = make_shared<S>(1, 2);
  (void)p;
}