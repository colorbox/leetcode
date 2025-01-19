/*
他の方のPRを見てprioority_queueの解法をベースに諸々を整えたパターンでstep3を実践
*/
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> num_to_count;
    for (int num : nums) {
      if (!num_to_count.contains(num)) {
        num_to_count[num] = 0;
      }
      num_to_count[num]++;
    }

    priority_queue<NumCount> num_count;
    for (auto [num, count] : num_to_count) {
      num_count.push({num, count});
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

    bool operator< (const NumCount& other) const {
      return count < other.count;
    }
  };
};
