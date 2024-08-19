class KthLargest {
public:
  KthLargest(int k, vector<int>& nums): capacity(k) {
    for (int num: nums) {
      if (heap.empty()) {
        heap.push_back(num);
        continue;
      }
      if (heap.size() == capacity && heap.front() >= num) {
        continue;
      }
      push_(num);
      if (heap.size() > capacity) {
        pop_();
      }
    }
  }
  
  int add(int val) {
    if (heap.empty()) {
      heap.push_back(val);
      return val;
    }
    push_(val);
    if (heap.size() > capacity) {
      pop_();
    }
    return heap.front();
  }
private:
  vector<int> heap;
  int capacity;

  int parent_index_(int child_index) {
    return (child_index - 1) / 2;
  }

  int left_child_index_(int parent_index) {
    return parent_index * 2 + 1;
  }

  int right_child_index_(int parent_index) {
    return parent_index * 2 + 2;
  }

  int min_child_index_(int parent_index) {
    int left = left_child_index_(parent_index);
    int right = right_child_index_(parent_index);
    if (right >= heap.size() || heap[right] > heap[left]) {
      return left;
    }
    return right;
  }

  void sift_up_() {
    int index = heap.size() - 1;
    if (index == 0) {
      return;
    }
    while (index > 0) {
      int parent_index = parent_index_(index);
      if(heap[index] > heap[parent_index]) {
        break;
      }
      swap(heap[index], heap[parent_index]);
      index = parent_index;
    }
  }

  bool has_child_(int index) {
    return (left_child_index_(index) < capacity);
  }

  void sift_down_() {
    int index = 0;
    while (has_child_(index)) {
      int min_child_index = min_child_index_(index);
      if (min_child_index >= heap.size() || heap[index] <= heap[min_child_index]) {
        break;
      }
      swap(heap[index], heap[min_child_index]);
      index = min_child_index;
    }
  }

  void push_(int val) {
    if (heap.size() == capacity && val < heap.front()) {
      return;
    }

    heap.push_back(val);
    sift_up_();
  }

  void pop_() {
    swap(heap.front(), heap.back());
    heap.pop_back();
    sift_down_();
  }
};
