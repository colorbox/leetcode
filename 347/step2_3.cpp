/*
priority_queueで実装するパターンで解く
*/
class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> frequency_counter;
    for (int num : nums) {
      if (!frequency_counter.contains(num)) {
        frequency_counter[num] = 0;
      }
      frequency_counter[num]++;
    }

    priority_queue<pair<int, int>> frequency_queue;
    for (auto pair : frequency_counter) {
      frequency_queue.push(make_pair(pair.second, pair.first));
    }
    vector<int> top_k_frequent_nums;
    for (int i = 0; i < k; i++) {
      top_k_frequent_nums.push_back(frequency_queue.top().second);
      frequency_queue.pop();
    }

    return top_k_frequent_nums;
  }
};
