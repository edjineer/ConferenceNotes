// g++-14 -c staticVsInline0.o
// g++-14 -c other.o
// g++-14 staticVsInline0.o other.o
#ifndef STATIC_VS_INLINE_H
#  define STATIC_VS_INLINE_H

static int StaticFun() { return 42; }

inline int InlineFun() { return 42; }

#endif /* STATIC_VS_INLINE_H */

int Something() { return InlineFun(); }

#ifndef STATIC_VS_INLINE_H
#  define STATIC_VS_INLINE_H

static int StaticFun() { return 42; }

inline int InlineFun() { return 42; }

#endif /* STATIC_VS_INLINE_H */

static int Nonsense() { return 5; }

int main() { return InlineFun(); }