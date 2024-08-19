class KthLargest {
public:
  KthLargest(int k, vector<int>& nums) {
    capacity = k;
    int count = 0;

    for (int num: nums) {
      if (count == capacity && saved_nums.begin()->first > num) {
        continue;
      }
      if (!saved_nums.contains(num)) {
        saved_nums[num] = 1;
        count++;
        continue;
      }
      saved_nums[num]++;
      count++;
    }
  }
  
  int add(int val) {
    if (!saved_nums.contains(val)) {
      saved_nums[val] = 1;
    } else {
      saved_nums[val]++;
    }

    removeSmallNums();

    return saved_nums.begin()->first;;
  }
private:
  map<int, int> saved_nums;
  int capacity;

  int countSavedNums() {
    int count = 0;
    for (const auto& pair: saved_nums) {
      count += pair.second;
    }
    return count;
  }

  void removeSmallNums() {
    int count = countSavedNums();

    while (count > capacity) {
      auto it = saved_nums.begin();
      if (it->second > 0) {
        it->second--;
        count--;
      }
      if(it->second == 0) {
        saved_nums.erase(it);
        continue;
      }
    }
  }
};
