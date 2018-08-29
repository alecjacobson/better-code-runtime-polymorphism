//  clang++ -std=c++11 client.cpp -o client && ./client
#include "library.hpp"
#include <iostream>
using namespace std;

class my_class_t {
  /* ... */
};

void draw(const my_class_t&, ostream& out, size_t position)
{ out << string(position, ' ') << "my_class_t" << endl; }

int main() {
  history_t h(1);
  current(h).emplace_back(0);
  current(h).emplace_back(string("Hello!")); 
  
  draw(current(h), cout, 0);
  cout << "--------------------------" << endl; 

  commit(h);

  current(h)[0] = 42.5;
  current(h)[1] = string("World");
  current(h).emplace_back(current(h));
  current(h).emplace_back(my_class_t());

  draw(current(h), cout, 0);
  cout << "--------------------------" << endl; 

  undo(h);

  draw(current(h), cout, 0);
}
