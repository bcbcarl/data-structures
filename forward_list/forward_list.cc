#include "forward_list.h"

namespace carl {
  template <typename T>
  ForwardList<T>::ForwardList() {
    list_ = nullptr;
  }

  template <typename T>
  ForwardList<T>::~ForwardList() {
    clear();
  }

  template <typename T>
  bool ForwardList<T>::empty() const noexcept {
    return list_ == nullptr;
  }

  template <typename T>
  const T& ForwardList<T>::front() const {
    return list_->val;
  }

  template <typename T>
  void ForwardList<T>::push_front(const T& val) {
    ListNode<T>* newNode = new ListNode<T>(val);

    if (empty()) {
      list_ = newNode;
    } else {
      newNode->next = list_;
      list_ = newNode;
    }
  }

  template <typename T>
  void ForwardList<T>::pop_front() {
    if (empty()) {
      return;
    }

    if (list_->next == nullptr) {
      delete list_;
      list_ = nullptr;
    } else {
      ListNode<T>* firstNode = list_;
      list_ = list_->next;
      delete firstNode;
    }
  }

  template <typename T>
  void ForwardList<T>::clear() noexcept {
    while (!empty()) {
      pop_front();
    }
  }

  template <typename T>
  void ForwardList<T>::reverse() noexcept {
    if (empty() || list_->next == nullptr) {
      return;
    }

    ListNode<T>* current = list_;
    ListNode<T>* prev = nullptr;
    ListNode<T>* next = nullptr;
    while (current != nullptr) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    list_ = prev;
  }

  template class ForwardList<int>;
}
