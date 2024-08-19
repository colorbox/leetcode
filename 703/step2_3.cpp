/*
heapを自前で実装
*/
class KthLargest {
public:
  KthLargest(int k, vector<int>& nums): capacity(k) {
    for (int num: nums) {
      push(num);
    }

    while (container.size() > capacity) {
      pop();
    }
  }

  int add(int val) {
    push(val);
    return top();
  }

private:
  vector<int> container;
  int capacity;

  int top() {
    return container.front();
  }
  
  void pop() {
    swap(container.front(), container.back());
    container.pop_back();
    sift_down_from_root();
  }

  void push(int val) {
    container.push_back(val);
    sift_up_from_leaf(container.size() - 1);
    while (size() > capacity) {
      pop();
    }
  }

  int size() {
    return container.size();
  }

  int parent_index(int child_index) {
    return (child_index - 1) / 2;
  }

  int left_child_index(int parent_index) {
    return parent_index * 2 + 1;
  }

  int right_child_index(int parent_index) {
    return left_child_index(parent_index) + 1;
  }
  
  void sift_down_from_root() {
    int parent = 0;
    while (true) {
      int left = left_child_index(parent);
      if (left >= size()) {
        return;
      }
      int min_child_index = left;
      int right = right_child_index(parent);
      if (right < size() && container[min_child_index] > container[right]) {
        min_child_index = right;
      }
      if (container[min_child_index] >= container[parent]) {
        return;
      }
      swap(container[parent], container[min_child_index]);
      parent = min_child_index;
    }
  }

  void sift_up_from_leaf(int index) {
    int child_index = index;
    int parent_index_ = parent_index(child_index);
    while (parent_index_ >= 0) {
      if (container[parent_index_] <= container[child_index]) {
        return;
      }
      swap(container[parent_index_], container[child_index]);
      child_index = parent_index_;
      parent_index_ = parent_index(parent_index_);
    }
  }
};
