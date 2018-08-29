//  clang++ -std=c++14 client.cpp -o client && ./client
#include "library.hpp"
#include <iostream>
using namespace std;

class my_class_t final : public object_t
{
  public: 
    void draw(ostream& out, size_t position) const override
    { out << string(position, ' ') << "my_class_t" << endl;}
    /* ... */
};

int main() {
  document_t document;

  document.emplace_back(make_shared<my_class_t>());

  draw(document, cout, 0); 
}
