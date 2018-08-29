#include <iostream>
#include <string>
#include <vector>
using namespace std;


void draw(const int& x, ostream& out, size_t position)
{ out << string(position, ' ') << x << endl; }

class object_t {
  public:
    object_t(const int& x) : self_(x)
    { }

    friend void draw(const object_t& x, ostream& out, size_t position)
    { draw(x.self_, out, position); }
  private:
    int self_;
};

using document_t = vector<object_t>;

void draw(const document_t& x, ostream& out, size_t position)
{
    out << string(position, ' ') << "<document>" << endl;
    for (const auto& e: x) draw(e, out, position + 2);
    out << string(position, ' ') << "</document>" << endl;
}
