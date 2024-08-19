class KthLargest {
public:
  KthLargest(int k, vector<int>& nums) : capacity(k) {
    for (int num: nums) {
      if (preserved_nums.size() < capacity) {
        push(num);
        continue;
      }
      if (num < preserved_nums.front()) {
        continue;
      }
      push(num);
      if (preserved_nums.size() > capacity) {
        pop();
      }
    }
  }
  
  int add(int val) {
    if (preserved_nums.empty()) {
      preserved_nums.push_back(val);
      return val;
    }
    if (preserved_nums.size() == capacity && preserved_nums.front() > val) {
      return preserved_nums.front();
    }
    push(val);
    if (preserved_nums.size() > capacity) {
      pop();
    }
    return preserved_nums.front();
  }
private:
  int capacity;
  vector<int> preserved_nums;

  int parent_index(int index) {
    return (index - 1) / 2;
  }

  void sift_up_from_last() {
    int index = preserved_nums.size() - 1;
    while (index > 0) {
      int parent_index_ = parent_index(index);
      if (preserved_nums[index] >= preserved_nums[parent_index_]) {
        break;
      }
      swap(preserved_nums[index], preserved_nums[parent_index_]);
      index = parent_index_;
    }
  }

  int left_child_index(int index) {
    return index * 2 + 1;
  }

  int right_child_index(int index) {
    return index * 2 + 2;
  }

  int min_child_index(int index) {
    int left = left_child_index(index);
    int right = right_child_index(index);
    if (right >= preserved_nums.size()) {
      return left;
    }
    if (preserved_nums[left] <= preserved_nums[right]) {
      return left;
    }
    return right;
  }

  bool has_child(int index) {
    return left_child_index(index) < preserved_nums.size();
  }

  void sift_down_from_root() {
    int index = 0;
    while (has_child(index)) {
      int min_child_index_ = min_child_index(index);
      if (preserved_nums[min_child_index_] >= preserved_nums[index]) {
        break;
      }
      swap(preserved_nums[min_child_index_], preserved_nums[index]);
      index = min_child_index_;
    }
  }

  void push(int num) {
    preserved_nums.push_back(num);
    sift_up_from_last();
  }

  void pop() {
    swap(preserved_nums.front(), preserved_nums.back());
    preserved_nums.pop_back();
    sift_down_from_root();
  }
};
