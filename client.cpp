//  clang++ -std=c++14 client.cpp -o client && ./client
#include "library.hpp"
#include <iostream>
using namespace std;

int main() {
  document_t document;
  document.reserve(5);

  document.emplace_back(0);
  document.emplace_back(1);
  document.emplace_back(2);
  document.emplace_back(3);

  reverse(document.begin(), document.end());

  draw(document, cout, 0); 
}
