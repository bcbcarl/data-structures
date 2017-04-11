#include "list.h"

namespace carl {
  template <typename T>
  List<T>::List() {
    list_ = nullptr;
    last_ = nullptr;
    size_ = 0;
  }

  template <typename T>
  List<T>::~List() {
    clear();
  }

  template <typename T>
  bool List<T>::empty() const noexcept {
    return size() == 0;
  }

  template <typename T>
  size_t List<T>::size() const noexcept {
    return size_;
  }

  template <typename T>
  const T& List<T>::front() const {
    return list_->val;
  }

  template <typename T>
  const T& List<T>::back() const {
    return last_->val;
  }

  template <typename T>
  void List<T>::push_front(const T& val) {
    ListNode<T>* newNode = new ListNode<T>(val);

    if (empty()) {
      list_ = newNode;
      last_ = newNode;
    } else {
      newNode->next = list_;
      list_ = newNode;
    }
    ++size_;
  }

  template <typename T>
  void List<T>::pop_front() {
    if (empty()) {
      return;
    }

    if (size() == 1) {
      delete list_;
      list_ = nullptr;
      last_ = nullptr;
    } else {
      ListNode<T>* firstNode = list_;
      list_ = list_->next;
      list_->prev = nullptr;
      delete firstNode;
    }
    --size_;
  }

  template <typename T>
  void List<T>::push_back(const T& val) {
    ListNode<T>* newNode = new ListNode<T>(val);

    if (empty()) {
      list_ = newNode;
      last_ = newNode;
    } else {
      last_->next = newNode;
      newNode->prev = last_;
      last_ = newNode;
    }
    ++size_;
  }

  template <typename T>
  void List<T>::pop_back() {
    if (empty()) {
      return;
    }

    if (size() == 1) {
      delete list_;
      list_ = nullptr;
      last_ = nullptr;
    } else {
      ListNode<T>* lastNode = last_;
      last_ = last_->prev;
      last_->next = nullptr;
      delete lastNode;
    }
    --size_;
  }

  template <typename T>
  void List<T>::clear() noexcept {
    while (!empty()) {
      pop_front();
    }
  }

  template <typename T>
  void List<T>::reverse() noexcept {
    if (empty() || size() == 1) {
      return;
    }

    last_ = list_;
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

  template class List<int>;
}
