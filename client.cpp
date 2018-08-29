//  clang++ -std=c++14 client.cpp -o client && ./client
#include "library.hpp"
#include <iostream>
using namespace std;

class my_class_t {
  /* ... */
};

void draw(const my_class_t&, ostream& out, size_t position)
{ out << string(position, ' ') << "my_class_t" << endl; }

int main() {
  document_t document;
  document.reserve(5);

  document.emplace_back(0);
  document.emplace_back(string("Hello!"));
  document.emplace_back(document);
  document.emplace_back(my_class_t());

  draw(document, cout, 0); 
}
