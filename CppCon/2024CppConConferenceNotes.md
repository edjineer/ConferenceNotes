# CppCon 2024 Full Conference Notes

## Recommended Reading

* What every programmer should know about memory by Ulrich Realper
* Works from SG21
* CppCore Guidelines
* MISRA Common Weakness Categories - Published Regularly
* PAS 8800 = AI in Automotive Working Group, Michael Wong repreents Canada in the working group
* CppInsights

### Questions for Future Rabbit Hole Explorations

* Clang and Beyond
  * LLVM 20: What is it, how does it evolve, differences for different
  * Differences between Clang Non-Allocating and Non-blocking
* Specific Libraries, Functions, and other mysterious acronyms mentioned throughout the conference
  * Spaceship Operator, its history, and its evolution throughout the standards
  * LLDB
  * Unifex Library
  * Co_bt (coroutine backtrace?)
  * Lib Unwind
  * ADL
  * Sutter Interface Principle
  * Compiler's Ranking system for function resolution
  * Qualified and Unqualified Names
  * Structural Types

## Talks Attended

### "LLVM's Realtime Safety Revolution: Tools for Modern Mission Control Systems" by Chris Apple and David Trevelyan

[Link To Talk](https://cppcon2024.sched.com/event/1gZgL/llvms-realtime-safety-revolution-tools-for-modern-mission-critical-systems)

[Link to RTSan Project](https://github.com/realtime-sanitizer/rtsan)

Notes and Key Features of RTSan:

* Autogenerated Documentation
* Real-Time Safety Guarantees
* CI Pipeline Integration
* LLVM 20/Clang 20 dependent for now
* Differences between Clang Non-Allocating and Non-blocking

### "How Meta Made Debugging Async Code Easier" by Jessica Wong and Ian Petersen

[Link to Talk Abstract](https://cppcon2024.sched.com/event/1gZgT/how-meta-made-debugging-async-code-easier-with-coroutines-and-senders)

[Link To Demo Project](https://github.com/fbsamples/cppcon24-async-demo)

Check out their episode of the CppCast for more details on this topic!

Topics I should investigate after this talk:

* LLDB
* Unifex Library
* Co_bt (coroutine backtrace?)
* Lib Unwind

### Safety and Security Panel

[Link to Abstract](https://cppcon2024.sched.com/event/1kYBw/safety-and-security-panel)

Hot Topics Discussed in this Panel:

* Contracts for Cpp26, and the proposal process
  * Very useful for testing
* Working Group 21
* ISO C++ Contracts for Safety and Security
* Question: How do you quantify safety in a C++ Code Base
* Safety as a foundational pillar for your organization
* RUST (gasp)
  * Safety by Default for Rust, but "unsafe" code is still possible
  * If starting a new code base from scratch today, options to consider
  * Type and memory safety are advantages that other languages have over C++
  * Herb Sutter Argues for Parity vs Perfection
  * Sean Baxter's Prototype of ["Safe, Borrow Checked C++"](https://cppcast.com/safe-borrow-checked-cpp/)
    * Some think that borrow checking was implemented a bit too literally, to a point where it's not even C++ code anymore, it is a rust imitation
    * Bloomberg is apparently dumping millions of dollars to follow up on that work
* Possible Definition of Correctness: Absence of undefined behavior?

### "Back to Basics: Function Resolution" by Ben Saks

[Link to Abstract](https://cppcon2024.sched.com/event/1gZdm/back-to-basics-function-call-resolution)

* ADL
* Sutter Interface Principle
* Compiler's Ranking system for function resolution
* Qualified and Unqualified Names
* Structural Types

### "Fast and Small C++ - When Efficiency Matters" By Andreas Fertig

[Link to abstract](https://cppcon2024.sched.com/event/1gZfc/fast-and-small-c-when-efficiency-matters)

* Takeaway: This was a fascinating talk detailing some creative (and a bit hacky too) ways to reduce the size of a common data structure like string. Many have embarked on the challenge: how small can I make this library? But this is an exploration of different approaches to optimize on size, and the costs of that optimization. 

### "Compile Time Validation" by Alon Wolf

[Link to abstract](https://cppcon2024.sched.com/event/1gZgF/compile-time-validation)

Topics covered, and those that I should look into afterwards: 