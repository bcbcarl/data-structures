#ifndef CARL_DEQUE_H
#define CARL_DEQUE_H

#include <list>

namespace carl {
  template <typename T>
  class Deque {
  public:
    bool empty() const noexcept {
      return deque_.empty();
    }

    size_t size() const noexcept {
      return deque_.size();
    }

    const T& front() const {
      return deque_.front();
    }

    const T& back() const {
      return deque_.back();
    }

    void push_front(const T& val) {
      deque_.push_front(val);
    }

    void push_back(const T& val) {
      deque_.push_back(val);
    }

    void pop_front() {
      deque_.pop_front();
    }

    void pop_back() {
      deque_.pop_back();
    }
  private:
    std::list<T> deque_;
  };
}

#endif // CARL_DEQUE_H
