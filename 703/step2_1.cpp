class KthLargest {
private:
  std::vector<int> heap;
  int size;
public:
  KthLargest(int k, vector<int>& nums): heap(nums), size(k) {
    // ソートしておけばmin heapとして問題ない状態になるはず
    sort(heap.begin(), heap.end());
    // heapの切り詰め、sizeで切り詰める
    while (heap.size() > k) {
      heap.erase(heap.begin());
    }
  }

  int add(int val) {
    heap.push_back(val);
    int child_index = heap.size() - 1;
    while (true) {
      int parent_index = (child_index - 1) / 2;
      if (heap[child_index] >= heap[parent_index]) {
        break;
      }
      swap(heap[child_index], heap[parent_index]);
      child_index = parent_index;
    }
    if (heap.size() <= size) {
      return heap.front();
    }
    swap(heap.front(), heap.back());
    heap.pop_back();
    int parent_index = 0;
    while (true) {
      int left_child_index = parent_index * 2 + 1;
      if (left_child_index >= heap.size()) {
        break;
      }
      int swap_target_index = left_child_index;
      int right_child_index = left_child_index + 1;
      if (right_child_index < heap.size() && heap[left_child_index] > heap[right_child_index]) {
        swap_target_index = right_child_index;
      }
      if (heap[swap_target_index] >= heap[parent_index]) {
        break;
      }
      swap(heap[parent_index], heap[swap_target_index]);
      parent_index = swap_target_index;
    }
    return heap.front();
  }
};

