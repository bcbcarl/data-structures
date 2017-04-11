#ifndef CARL_STACK_H
#define CARL_STACK_H

#include <list>

namespace carl {
  template <typename T>
  class Stack {
  public:
    bool empty() const noexcept {
      return stack_.empty();
    }

    size_t size() const noexcept {
      return stack_.size();
    }

    const T& top() const {
      return stack_.back();
    }

    void push(const T& val) {
      stack_.push_back(val);
    }

    void pop() {
      stack_.pop_back();
    }
  private:
    std::list<T> stack_;
  };
}

#endif // CARL_STACK_H
