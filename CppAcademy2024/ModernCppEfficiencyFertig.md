# Andreas Fertig CppAcademy

https://wg21.link/std

- 2000 pages, lawyer-y english
- 1/3 language 
- 2/3 Standard library
- Cpp Reference Pulls from it
wandbox.org
cppinsights.io
- Can run locally
General Embedded Guidelines
- No heap
- No exceptions
University of Washington Course 13 week in cpp

Random

- Uniform initialization across standards
- printf vs puts
- Deep Dive Initializer Lists
- What is the real difference between auto as a type, and what can go in from vector<int>
- Local Godbolt
- O3 flag vs O0 flags (optimization levels)
- Project Idea: constexpr, will it help me

## Smaller Language Features

Uniform Initialization

- Use u{}
- Avoids narrowning conversion; parentheses will implictly convert
- Anything that can be interpreted as a function protoype will be interpreted as a function prototype
- Resource Acqiusiion is initialization
- std::initializer_list
  - Do not use for anything other than initialization
  - Usually an initializer list item is not of class type
- std::vector changed across standard
- Designated Initializers: relies on the right order
- Order always matters; class construction over initalization order

NoExcept

- We pay for exceptions: need overhead for unwinding
- Guarantees that it wont throw
- Compiler still won't trust us: it wraps it in a try/catch. Does this for Move semantics
- Useful to have noexcept to save Ram and Rom
- Try afterwards: cppinsights, nest noexcepts from calees

If and Switch with Initialization

Default Member Initialization

- Cpp11, class members can be initialized inline with a default

Constructor Inheritance 

static vs inline 

- Inlinig: assesses if cheaper to copy over your function than do a function
- Inline does not imply that it gets inlined
- How is the functiontrated when it is in global scope
- Typically go as inline: will not duplicae
- Inline suppresses the One Definition rule

CTAD

- Class Template ARgument Deduction
- Can guess from parameters in
- Non-type, not the same as adding auto in there. Can deduce
- Vs make_NNN

Summary

- Use initializer_list to initialize objects
- Avoid class operators or special member functions with an initializer list as a parameter
- Prefer CTAD over make_pair/NNN functions. Those make_CXXX are expensive

## constexpr: Compile time

Compile Time bs Run Time, Constexpr

- Some calculations are done in compile time, that is constexpr
- Run time as default
- Constexpr C++11
- No undefined behavior allowed
- Your constexpr sections will be less than other code in code base
- Lambdas are implicitly constexpr
- = default is implicitly constexpr
- Only literal types are allowed as parameters
- Constexpr ahs a dual nature, will run at comile time if compile time context is required, but may not work all the time
- Constexpr is implicitly inline
- Efficiency ranking: static, inline, constexpr in that order

## Lambdas

- Anonymous functions
- []()->
- Init captures
- Introduce to lambda with new name
- Great Evolution diagram
- Single shots is just ()
- Can call it multiple times
- Lamda internally is a class 