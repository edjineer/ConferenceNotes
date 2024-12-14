# CppCon 2024 Full Conference Notes

## List of topics to revisit

* Modern C++ Design by Andre Alexandrescu
* "Constexpr all the things" 2017 talk from Ben Deane and Jason Turner
* Book Recommendation: Data structures and Algorithms with the c++ STL by John Farrier
* Linux fun: "ulimit -s" will let you find the size of your stack. Neat!
* 2019 talk: "getting allocators out of our way"
* Youtube recommendation: "C++ STL Write an iterator from scratch, modern C++ with Mike" Mike Shah
* niohmann library for json
* Patrice Roy Memory Management Talks

## Almost Always Vector: Kevin Carpenter

[Link to talk:](https://www.youtube.com/watch?v=VRGRTvfOxb4)

Notes:

* Takeaway: Std::Vector should be the default container for you in Cpp
* Arrays
  * c style array is stack allocated.
  * Has fixed size. Cannot delete elements, best you can do is zero it out
  * Risk: extending beyond the end of an array
* Vector
  * 1992 Paper "Generic Dynamic Arrays" - Steinweller and von Zitzewiltz
  * is heap allocated, but allows to grow dynamically
* Basics and Memory management
  * DynArray transitioned to Vector
  * In 32 years, there are 32 member functions
  * Vector will default initialize to 0s
  * .at vs indexing. At will catch errors for you if you exceed bounds. If you directly index it, then cpp will let you exceed and grab garbage
  * .data will return a c-behaving pointer to the front of the structure
  * Vector allocates memory on the heap
    * Stack memory is small and limited
    * Comparison of Stack vs heap [22:00]
    * Pros of Stack: Use it when data is small, doesnt need to persist beyond your function and you want speed
      * Fast: pointer adjustment
      * Automatic: easy clean up
      * Predictable: easy to debug
      * Locality: cache performance
      * Safety: see automatic
    * Pros of Heap: Use it when data is large, needs to persist and flexible. But watch out. 
      * Flexible: dynamic at runtime
      * Large: bigger
      * Lifetime: not function dependent
      * Sharing: can share between threads
  * Size(amount of items in it) vs Capacity(how many more items can go in before you need to reallocate memory) [23:00]
    * Vector takes a guess of how big you actually need it to be before it resizes 
    * .reserve will let you be efficient up front: give it its ending size. Can happen after initialization. A good tool for efficiency 
    * .shrink_to_fit: not a guarantee that it releases the memory. Dependent on the implementation.
  * Allocators as an option for even more performance
* Iterators
  * Nicely wrapped pointer with guard rails
  * .begin = first item
  * .end super useful to not go past end
  * Is a pointer, but is also an abstraction with guard rails
  * .rend and rbegin, are reverse iterators
  * Range Based For Loop
    * Makes a copy every time in range based 
    * If you want to modify content, use iterator(dont modify size tho plz)
  * [CppReference Different Types of Iterators](https://en.cppreference.com/w/cpp/iterator)
  * Invalidation: If the vecotr reallocated on a write, then you need a new iterator because it might have reallocated memory and your iterator is invalid now
  * [CppReference Iterator Invalidation](https://en.cppreference.com/w/cpp/container)
* Algorithms: Unary Predicates and Iterators
  * Example: std::find with begin, end, and unary predicate of isEven to find first even number
  * You can specify range to get what you need
  * Lambdas work for unary predicates too
* Container Comparisons
  * std::list
    * Doubly linked list
    * Good for insertion and deletion at arbitrary positions
  * std::deque
    * Non contiguous memory, but supports random access
    * Fast insertion and removal at both ends
    * Less cache efficient, uses more memory
    * Use it for efficient removal+insertion at both ends
  * std::map
    * Youtube
* Why almost always vector
  * Efficiency
    * Amortized constant growth
  * Practicality
    * Random Access
    * Automatic memory management
    * Sorts easy
  * Versatility
* General Advice
  * Read technical books as a techincal editor, get free copies, and enhance your skillzzzzz
* Discussion Topics:
  * [2:24] Code snippet why broken here. ```int a[SIZE_EXPECTED_HERE] = {0,1,3,4}```. List Initialization explained [cppreference](https://en.cppreference.com/w/cpp/language/list_initialization)
  * Good Cpp Insights Example: ```int cppConEarlyYears[6] = {2014, 2015, 2016};```
  * [6:37] Why cant we copy on line 9? Godbolt says "Array initializer must be initializer list"

## Peering Forward: C++'s Next Decade- Herb Sutter

[Link to talk](https://www.youtube.com/watch?v=FNi1-x4pojs)

Notes:

* [2:20] Major Advances for Cpp26
  1. Reflections-P2996: Meta program; lets us write programs that write other programs. Other languages have run time meta programming that is slow; cpp26 is compile time
  2. Memory Safety Parity
* Context for Cpp26
  * In Sept 2024, only 9 months away from Cpp26
* History of other updates to the standard
  * Constexpr came in cpp11, and evolved to make other compile time
  * GPUs: similar evolution to constexpr
  * Reflection is stepwise as well [12:00]

