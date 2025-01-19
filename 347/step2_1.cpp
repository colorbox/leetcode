class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> counter;
    for (auto num : nums) {
      if (!counter.contains(num)) {
        counter[num] = 0;
      }
      counter[num]++;
    }
    vector<int> heap;
    for (auto pair : counter) {
      heap.push_back(pair.second);
      push_heap(heap.begin(), heap.end(), std::greater<int>());
      if (heap.size() > k) {
        pop_heap(heap.begin(), heap.end(), std::greater<int>());
        heap.pop_back();
      }
    }
    set<int> top_nums;
    for (auto num : heap) {
      top_nums.insert(num);
    }
    vector<int> top_frequent_nums;
    for (auto pair : counter) {
      if (!top_nums.contains(pair.second)) {
        continue;
      }
      top_frequent_nums.push_back(pair.first);
    }
    return top_frequent_nums;
  }
};
