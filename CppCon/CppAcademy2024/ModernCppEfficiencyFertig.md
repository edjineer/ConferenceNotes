# Andreas Fertig CppAcademy

https://wg21.link/std

- 2000 pages, lawyer-y english
- 1/3 language
- 2/3 Standard library
- Cpp Reference Pulls from it
- wandbox.org
- cppinsights.io
- Can run locally
- General Embedded Guidelines
  - No heap
  - No exceptions
- University of Washington Course 13 week in cpp

Random

- Uniform initialization across standards
- printf vs puts
- Deep Dive Initializer Lists
- What is the real difference between auto as a type, and what can go in from vector<int>
- Local Godbolt
- O3 flag vs O0 flags (optimization levels)
- Project Idea: constexpr, will it help me
  - Assess Script: Summarized opportunities to improve performance
  - Apply Script: Apply, reap the benefits
- Follow up: when and why does constexpr help, deep dive
- constexpr if
  - also using it over enable_if
- std::enable_if_t
- How to handle the ODR
- std::forward, perfect forwarding
- LVal, RVal, Ref Qualifiers, & and &&
- Singletons
- std::optional
- Practice: which is better, emplace_back vs push_back for vector
- How do we measure in Code benchmarks: 


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
- Applying Lambdas
  - Doesnt necessarily save much between lambdas and funcions. But compiler doing it might be more efficient
  - Using trailing return tail when you don't want to static cast things under the hood
- Cpp14 Generic Lambdas
  - Use Auto in () function calls
  - Templates it out
  - Assumes no connection between the two
  - Once you see "auto" in a lambda, it is actually a template
  - Templates risk: we generate more code in the back than we intend to
- IIFE = Immediately invoked function expression. Enables more const within
- Exercise:
  - Make it a std::string object, user-defined literal

## Speedy Templates

- Variadic Templates
  - printf puts everything on the stack
  - Three dots indicate "however many arguments"
  - T = single, Ts = multiple Ts
  - Parameter Pack
    - sizeof...(vals) gets size of pack
    - Multiple types can be in parameter pack
- Considerations
  - Compiler can optimize away to low level
  - Depth of recursion plays a role: and tail recursion is an optimization, but it can only go so far
  - std::enable_if_t used to save issues from junior engineers
- Fold Expressions
  - How to tell that the template values match: std::conjunction_v<std::is_same<T,Ts>...>
- Variable Templates (C++14, some details 17)
  - Template MetaProgramming
  - Stay away from && (r value references)
- Use constexpr if over enable if
  - Compile time more efficient version, and more maintainable
- Extern Template
  - Don't do it unless there is pain there
  - Affects the Instantiation

## Move Semantics

ACCU Paper describing rvalue, lvalue, others
Value categories, Andreas Schnaut Knatten
Rule of 3, Rule of 5 = Scott Meyers

- Special Member Functions and dependencies
  - Not declared move when user declares things
  - Rule of 5
  - Might not mind having less but should do it
- Emplace_back is slightly more efficient than push back; emplace back can make it in place, done better than making a temporary object
- Std::Vector
  - Vector internals
  - Exception Guarantee: system with limited memory and push back
  - Move constructor should have noexcept: move is a destroying operation, so noexcept helps. Move assignment operation should also have noexept
  - Libc++ doubles size, MS does 1.5 when expansion is needed
- LVal and RVal
  - lavlues are &, named objects
  - rvalues && are untitled, nameless, temporary
- Perfect Forwarding
  - std::forward figures out whether to move or forward, also considers T
- Ref Qualifiers
  - Can optimize by distinguishing for rval an lvals for functions
  - Is the only context where you should bmove a return value
- Move semantics has higher priority than copy semantics
- Mark move ctor and assignment operator with noexcept

## Abstractions Costs

- static
  - Block local static
- Singleton
  - cxa guards are in the compiler
- Smart Pointers
  - RAII
  - Kinda garbage collection for c++
  - 3 Versions:
    - unique_ptr
      - Theme is ownership
      - If you have heap data, then unique_ptr can be your friend
      - use make_unique
    - shared_ptr: has reference count, releases when last one is deleted
      - use_count function can be counted
      - Increment and decrement of usecount is atomic
    - weak_ptr
      - Cyclic references can be broken up
      - One is defined as weaker while other is shared_ptr
      - Make shared
      - Weak pointers can stall the memory

## STL

- Guidelines
  - Prefer member functions over functions that are generic with same name (prefer vector_sort over sort on a vector)
  - std::vector by default for variable length container (even over map)
    - std::map does pointer chasing, and is worse than a vector pair where you search through every item
    - std::vector uses cache lines
    - Can be supported by measuring
    - Bjarne talk: std::list, vector is better due to caching
  - If you need fixed size container, use std::array
- Push_back and emplace_back
- For Vector, pre-reserve if you know how big it will be
  - v.reserve
  - Shrink to fit is an option for vector, but you copy all your existing data, so there's a tradeoff
- std::vector is great for caching, don't use list
- Use deque if you want to add and remove at both ends, its a double linked list
- Use push_back or emplace_back smartly; new vs existing temporary objects

## Misc

Large Code Base assessments

- snprintf, added 700 bytes
- Grade heat map, bar graph, find by large binary size
- Valgrind and cachegrind and IDEs to visualize which is the slowest or cache misses
- perf for throughput
- CI system to see whats happening as it happens, measurements
- Capture the past to know when the change went in
- Make binary reproducible builds (like paths, usernames, timestamps)
- git bisect
- VSCode analyzer
- Code coverage, count how often code is called, identify hotspots
- Bjarne Fuller talk: writing cache friendly c++. Works in networking
- Look at binaries in hex editors
- Generated map file of your binary
- Reduce padding
- Lint time optimizations
- Profile guided optimizations: it will rearrange

Compilers

- Clang AST
- Write your own 
- Open souce compilers
- Qual type, declaration, expression, 
- Etc: patch clang coroutines
- Jenna Carouse: 
- LLVM Meetings, they have a conference
- Compuler, feature extensions
- Every compile looks diffrent 
- Settle with one compiler 
- Write an extension for clangtidy
  - Enforce coding guidelines
  - Clang tooling 
  - Clang to compile, add a tool, make it work elsewhere 
  - Pull from trunk 
