# First In-Person CppCon Notes: 2023 Free Friday

## Follow Up Topics

* Special Members by Howard Hinnant
* shared_ptr vs unique_ptr vs weak_ptr
* Ins and outs of =default
* extern
* noexcept
* Compile provided
* Sanitizers, specifically: use after free, double deletion
* Value Categories
* std::move

## Talks Attended

### Back to Basics: The Rule of 5  by Andre Kostur

[Link to Talk](https://www.youtube.com/watch?v=juAZDfsaMvY)

Notes

* Pre-Reading: C++ Core Guideline and Rule of Five 
* How it Came about
* Basics
  * C++ is by default a value-based language
  * Well defined object lifetime model
  * Core Guidelines
    * Use RAII
    * C.21 is The Rule of Five
* Example
  * Move semantics introduced in C++11
  * Move constructor vs move assignment operator
* Rule of 5 C.21
  * If you definee or delete any copy, move or destructor, you should do something special in all of them
    * Copy Constructor
    * Copy Assignment Operator
    * Move Consrtuctor
    * Move Assignment Operator
    * Destructor
* Compiler Geneated Functions
  * Comiler will try, but it might SUCK
  * Special Members by Howard Hinnant
  * Rule of 5 is bottom section of the chart, supply all 5
  * Many different smart pointers, know the differences there
* C.20: Rule of Zero: If you can avoid naming any, avoid it
* Extended String Example
  * Code isnt just for the compiler
  * Only providing one or two is a problem
* Reminder: delete vs delete[]

### Building Consensus in a Massive Codebase by Sherry Sontag

[Link to Talk](https://www.youtube.com/watch?v=-Bth3PFsrsw)

Notes:

* Driving Question: long vs short namespaces
* Qualities of an investigative journalist: Humble, generous, asking questions
* Shared System Key Attributes
  * Automated
  * Enforced across the board, and early
  * Easy to follow
  * Buy in and trust
  * Enhancement, not erasure
  * Use a registration system
* Consensus is NOT 100% agreement

### Back to Basics: Forwarding References

[Link to Talk](https://www.youtube.com/watch?v=0GXnfi9RAlU)

Notes

* Value Categories
  * gValue, rValue, lValue, xValue, prValue
* Examples in the slides
* Binding and Pointers
  * Ptr vs reference: Differences in passing into a function
  * Pointers = obj
  *Reference = alias
  * Cool Table
  * Use references when you can, pts when you have to
* rValue Details
* Forwardng Reference
  * Deduced Function Template Parameter
  * CV Unqualified type template parameter
* Universal Reference
* Forwarding function parameters
* Perfect Forwarding
  * Preserve value category by means of std::forward value category
* Sink
  * convertible_to <>
  * std::constructible_from
* Underscore at the end of a declared variable
* Co-routines: capture the argument, decltypes


### Robots are after your job by Andrei Alexandrescu

[Link to Talk](https://www.youtube.com/watch?v=J48YTbdJNNc)

* Driving Question: which parts of the intricate C++ ecosystem can we confidently delegate to generative AI? What uniquely human skills must we retain and refine?

### Getting Started with C++ by Michael price

[Link To Talk](https://www.youtube.com/watch?v=NReDubvNjRg)

