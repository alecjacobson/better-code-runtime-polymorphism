# Better Code: Runtime Polymorphism 

[talk-slides]: http://sean-parent.stlab.cc/presentations/2017-01-18-runtime-polymorphism/2017-01-18-runtime-polymorphism.pdf

Git walk through of the C++ code presented in Sean Parent's talk [Better Code:
Runtime Polymorphism][talk-slides].

Casual C++ programmers or CS undergrads will be familiar with the
object-oriented code up to the "slide 13" commit. The use of the C++11 feature
`std::shared_ptr` may be new and the memory leak fixed in "slide 13 (leak fix)"
may cause a mild surprise. The subsequent transformations go on to show the true
power of new C++ features (C++11 and C++14) and the result is _very_ client
friendly code (at the price of the library containing some albeit convoluted
gobbledygook C++ boilerplate).

[github-commits-page]: https://github.com/alecjacobson/better-code-runtime-polymorphism/commits/master

The [git commits][github-commits-page] of this repository are labeled with
"slide x" where x corresponds to the slide number in the corresponding [talk by
Sean parent][talk-slides] to moments where he compiles and runs the code.
Through these commits you will see the transformations he applies. I have mostly
faithfully copied his code examples, adding necessary `#include`s and `using
namespace` lines to get it to compile.

Most of the time the only necessary compilation flag is C++11 support. When
`unique_ptr`s are briefly used you may need C++14.

For example, on Mac OS X with Apple LLVM version 9.1.0 (clang-902.0.39.2) you
can compile and run for any commit with
    
    clang++ -std=c++14 client.cpp && ./a.out
