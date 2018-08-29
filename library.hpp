#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;


template <typename T>
void draw(const T& x, ostream& out, size_t position)
{ out << string(position, ' ') << x << endl; }

class object_t {
  public:
    template <typename T>
    object_t(T x) : self_(make_unique<model<T>>(move(x)))
    { }

    object_t(const object_t& x) : self_(x.self_->copy_())
    { cout<< "copy" << endl; }
    object_t(object_t&& x) noexcept = default;

    object_t& operator=(const object_t& x)
    { return *this = object_t(x); }
    object_t& operator=(object_t&&) noexcept = default;

    friend void draw(const object_t& x, ostream& out, size_t position)
    { x.self_->draw_(out, position); }
  private:
    struct concept_t {
      virtual ~concept_t() = default;
      virtual unique_ptr<concept_t> copy_() const = 0;
      virtual void draw_(ostream&, size_t) const = 0;
    };
    template <typename T>
    struct model final : concept_t {
      model(T x) : data_(move(x)) { }
      unique_ptr<concept_t> copy_() const override
      { return make_unique<model>(*this); }
      void draw_(ostream& out, size_t position) const override
      { draw(data_, out, position); }

      T data_;
    };

    unique_ptr<concept_t> self_;
};

using document_t = vector<object_t>;

void draw(const document_t& x, ostream& out, size_t position)
{
    out << string(position, ' ') << "<document>" << endl;
    for (const auto& e: x) draw(e, out, position + 2);
    out << string(position, ' ') << "</document>" << endl;
}

using history_t = vector<document_t>;

void commit(history_t& x){ assert(x.size()); x.push_back(x.back()); }
void undo(history_t& x) { assert(x.size()); x.pop_back(); }
document_t& current(history_t& x) { assert(x.size()); return x.back(); }
