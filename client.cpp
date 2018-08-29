//  clang++ -std=c++14 client.cpp -o client && ./client
#include "library.hpp"
#include <iostream>
using namespace std;

struct some_t {
    object_t member_;
};

some_t func() { return { 5 }; }

int main() 
{
  /*  
      Quiz: what will this print?
  */
  some_t x = { 0 };

  x = func();
}
