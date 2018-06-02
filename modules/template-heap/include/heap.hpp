/* Copyright 2018 TolyaTalamanov */

#ifndef MODULES_TEMPLATE_HEAP_INCLUDE_HEAP_HPP_
#define MODULES_TEMPLATE_HEAP_INCLUDE_HEAP_HPP_

#include <iterator>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <utility>
#include <functional>

using std::size_t;

namespace atal {

template<class T,
         class Compare = std::less<T>
         >

class heap {
 public:
  heap() = default;
  explicit heap(size_t size) : m_d(2) { m_nodes.reserve(size); }

  template<typename Iterator>
  heap(Iterator first, Iterator last) : m_nodes(first, last), m_d(2) {
    for (int i = m_nodes.size() / m_d; i >= 0; --i) {
      shiftDown(i);
    }
  }

  heap(std::initializer_list<T> l) : heap(l.begin(), l.end()) {}

  heap(const heap& other) : m_nodes(other.m_nodes),
                            m_d(other.m_d),
                            m_comp(other.m_comp) {}

  heap(heap&& other) : m_nodes(std::move(other.m_nodes)), // NOLINT
                       m_d(other.m_d),
                       m_comp(std::move(other.m_comp)) {}

  void swap(heap& other) noexcept {
    using std::swap;
    swap(m_d, other.m_d);
    swap(m_comp, other.m_comp);
    m_nodes.swap(other.m_nodes);
  }

  heap& operator=(const heap& other);
  heap& operator=(heap&& other); // NOLINT

  size_t size() { return m_nodes.size(); }
  size_t getDim() { return m_d; }

  void setDim(int d) {
    if (d < 2) throw std::logic_error("invalid dimension");
    m_d = d;
  }

  bool empty() { return m_nodes.empty(); }

  void push(T value);
  void pop();
  T top();

  template<class ...Args>
  void emplace(Args&&... args) { // NOLINT
    m_nodes.emplace_back(std::forward<Args>(args)...);
    shiftUp(m_nodes.size() - 1);
  }

 private:
  void shiftUp(int node_index);
  void shiftDown(int node_index);

  int getLeftChild(int node_index);
  int getRightChild(int node_index);
  int getParrent(int node_index);
  int getMaxChild(int node_index);

 private:
  std::vector<T> m_nodes;
  size_t m_d;
  Compare m_comp;
};

template<class T, class Compare>
heap<T, Compare>&
heap<T, Compare>::operator=(const heap<T, Compare>& other) {
  if (this != &other) {
    m_nodes = other.m_nodes;
    m_d = other.m_d;
    m_comp = other.m_comp;
  }
  return *this;
}

template<class T, class Compare>
heap<T, Compare>&
heap<T, Compare>::operator=(heap<T, Compare>&& other) { // NOLINT
  if (this != &other) {
    m_nodes = std::move(other.m_nodes);
    m_d = other.m_d;
    m_comp = other.m_comp;
  }
  return *this;
}

template<class T, class Compare>
void heap<T, Compare>::push(T value) {
  m_nodes.push_back(value);
  shiftUp(m_nodes.size() - 1);
}

template<class T, class Compare>
T heap<T, Compare>::top() {
  if (empty()) {
    throw std::logic_error("heap is empty");
  }
  return m_nodes.front();
}

template<class T, class Compare>
void heap<T, Compare>::shiftUp(int node_index) {
  int parrent = getParrent(node_index);

  while (node_index > 0 && m_comp(m_nodes[parrent], m_nodes[node_index])) {
    std::iter_swap(m_nodes.begin() + node_index, m_nodes.begin() + parrent);
    node_index = parrent;
    parrent = getParrent(parrent);
  }
}

template<class T, class Compare>
void heap<T, Compare>::shiftDown(int node_index) {
  int max_child_pos = getMaxChild(node_index);

  while (max_child_pos != -1 &&
         m_comp(m_nodes[node_index], m_nodes[max_child_pos])) {
    std::iter_swap(m_nodes.begin() + max_child_pos,
                   m_nodes.begin() + node_index);

    node_index = max_child_pos;
    max_child_pos = getMaxChild(max_child_pos);
  }
}

template<class T, class Compare>
int heap<T, Compare>::getLeftChild(int node_index) {
  int j = m_d * node_index + 1;

  if (j >= size()) {
    j = -1;
  }

  return j;
}

template<class T, class Compare>
int heap<T, Compare>::getRightChild(int node_index) {
  int j = getLeftChild(node_index);

  if (j != -1) {
    j = std::min<int>(j + 1, size() - 1);
  }
  return j;
}

template<class T, class Compare>
inline
int heap<T, Compare>::getParrent(int node_index) {
  return (node_index - 1) / m_d;
}

template<class T, class Compare>
int heap<T, Compare>::getMaxChild(int node_index) {
  int l_child  = getLeftChild(node_index);
  int r_child  = getRightChild(node_index);
  int max_child_pos;

  if (l_child == -1) {
    max_child_pos = -1;
  } else if (r_child != -1) {
  auto pos_l = m_nodes.begin() + l_child;
  auto pos_r = m_nodes.begin() + r_child + 1;

  auto max_child_it = std::max_element(pos_l, pos_r, m_comp);
  max_child_pos = std::distance(m_nodes.begin(), max_child_it);
  } else {
    max_child_pos = l_child;
  }

  return max_child_pos;
}

template<class T, class Compare>
void heap<T, Compare>::pop() {
  if (!empty()) {
    std::iter_swap(m_nodes.begin(), m_nodes.end() - 1);
    m_nodes.pop_back();
    shiftDown(0);
  }
}
}  // namespace atal
#endif  // MODULES_TEMPLATE_HEAP_INCLUDE_HEAP_HPP_
