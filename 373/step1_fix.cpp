/*
step1 after review
*/

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int64_t left = nums1.front() + nums2.front();
    int64_t right = nums1.back() + nums2.back() + 1;
    while (left < right) {
      int64_t mid = left + (right - left) / 2;
      int count = count_less_pairs(nums1, nums2, mid, k);
      if (count >= k) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    int max_sum = left;
    priority_queue<SumPair> sum_pairs;
    for (int num1 : nums1) {
      for (int num2 : nums2) {
        if (num1 + num2 > max_sum) {
          break;
        }
        sum_pairs.push({num1 + num2, {num1, num2}});
        if (sum_pairs.size() > k) {
          sum_pairs.pop();
          if (num1 + num2 == sum_pairs.top().sum) {
            break;
          }
        }
      }
    }

    vector<vector<int>> answer;
    while (!sum_pairs.empty()) {
      answer.push_back(sum_pairs.top().pair);
      sum_pairs.pop();
    }
    return answer;
  }
 private:

  struct SumPair {
    int sum;
    vector<int> pair;

    bool operator< (const SumPair& other) const {
      return sum < other.sum;
    }
  };
 
  int count_less_pairs(vector<int> nums1, vector<int>nums2, int num, int limit) {
    int num_pairs = 0;
    for (int num1 : nums1) {
      auto it = upper_bound(nums2.begin(), nums2.end(), num - num1);
      num_pairs += distance(nums2.begin(), it);
      if (num_pairs > limit) {
        return limit;
      }
    }
    return num_pairs;
  }
};
