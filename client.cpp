//  clang++ -std=c++14 client.cpp -o client && ./client
#include "library.hpp"
#include <iostream>
using namespace std;

int main() {
  document_t document;
  document.emplace_back(0);
  document.emplace_back(1);
  document.emplace_back(2);
  document.emplace_back(3);
  draw(document, cout, 0); 
}
