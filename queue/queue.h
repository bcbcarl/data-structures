#ifndef CARL_QUEUE_H
#define CARL_QUEUE_H

#include <list>

namespace carl {
  template <typename T>
  class Queue {
  public:
    bool empty() const noexcept {
      return queue_.empty();
    }

    size_t size() const noexcept {
      return queue_.size();
    }

    const T& front() const {
      return queue_.front();
    }

    void push(const T& val) {
      queue_.push_back(val);
    }

    void pop() {
      queue_.pop_front();
    }
  private:
    std::list<T> queue_;
  };
}

#endif // CARL_QUEUE_H
