#ifndef CARL_LIST_H
#define CARL_LIST_H

#include <cstddef>

namespace carl {
  template <typename T>
  struct ListNode {
    T val;
    ListNode<T>* prev;
    ListNode<T>* next;
    ListNode<T>(T x): val(x), prev(nullptr), next(nullptr) {}
  };

  template <typename T>
  class List {
  public:
    List();
    ~List();
    bool empty() const noexcept;
    size_t size() const noexcept;
    const T& front() const;
    const T& back() const;
    void push_front(const T& val);
    void pop_front();
    void push_back(const T& val);
    void pop_back();
    void clear() noexcept;
    void reverse() noexcept;
  private:
    ListNode<T>* list_;
    ListNode<T>* last_;
    size_t size_;
  };

  extern template class List<int>;
}

#endif // CARL_LIST_H
