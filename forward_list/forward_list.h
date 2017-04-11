#ifndef CARL_FORWARD_LIST_H
#define CARL_FORWARD_LIST_H

namespace carl {
  template <typename T>
  struct ListNode {
    T val;
    ListNode<T>* next;
    ListNode<T>(T x): val(x), next(nullptr) {}
  };

  template <typename T>
  class ForwardList {
  public:
    ForwardList();
    ~ForwardList();
    bool empty() const noexcept;
    const T& front() const;
    void push_front(const T& val);
    void pop_front();
    void clear() noexcept;
    void reverse() noexcept;
  private:
    ListNode<T>* list_;
  };

  extern template class ForwardList<int>;
}

#endif // CARL_FORWARD_LIST_H
