/*
priority_queueの最大サイズを制限する
*/
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> num_to_count;
    for (int num: nums) {
      num_to_count[num]++;
    }

    priority_queue<NumCount, vector<NumCount>, greater<NumCount>> num_count;
    for (auto [num, count] : num_to_count) {
      num_count.push({num, count});
      if (num_count.size() > k) {
        num_count.pop();
      }
    }

    vector<int> answer;
    for (int i = 0; i < k; i++) {
      answer.push_back(num_count.top().num);
      num_count.pop();
    }
    return answer;
  }

 private:
  struct NumCount {
    int num;
    int count;

    bool operator> (const NumCount& other) const {
      return count > other.count;
    }
  };
};
