#include <iostream>
#include <string>
#include <vector>
using namespace std;


void draw(const int& x, ostream& out, size_t position)
{ out << string(position, ' ') << x << endl; }

class object_t {
  public:
    object_t(const int& x) : self_(make_unique<int_model_t>(x))
    { }
    object_t(const object_t& x) : self_(make_unique<int_model_t>(*x.self_))
    { }
    object_t& operator=(const object_t& x)
    { object_t tmp(x); self_ = move(tmp.self_); return *this; }

    friend void draw(const object_t& x, ostream& out, size_t position)
    { x.self_->draw_(out, position); }
  private:
    struct int_model_t {
      int_model_t(const int& x) : data_(x) { }
      void draw_(ostream& out, size_t position) const
      { draw(data_, out, position); }

      int data_;
    };

    unique_ptr<int_model_t> self_;
};

using document_t = vector<object_t>;

void draw(const document_t& x, ostream& out, size_t position)
{
    out << string(position, ' ') << "<document>" << endl;
    for (const auto& e: x) draw(e, out, position + 2);
    out << string(position, ' ') << "</document>" << endl;
}
