/*
1時間以上

Time: O( log(max(nums1,nums2)) * n log(m) )
Space: O( k )
n = nums1.size()
m = nums2.size()

nums1,nums2のすべてのペアを検証すると時間が足りないので、それを補う方法を考える。
ペアの数がk個以下となるような値Lを二分探索で探す。
合計値がL以下のペアをpriority_queueにいれて最小k個のペアを探す。
・二分探索での桁溢れ
・同値のペアが大量に作成される
などの問題を都度修正したら過アンリ時間がかかってしまったがかろうじてパスはしたものの
色々と筋悪な回答なのでstep2以降で修正する。

*/
class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    long long int left = nums1.front() + nums2.front();
    long long int right = nums1.back() + nums2.back() + 1;
    long long int mid;
    while (left + 1 < right) {
      mid = left + (right - left) / 2;
      int count = count_less_pairs(nums1, nums2, mid, k);
      if (count >= k) {
        right = mid;
      } else {
        left = mid;
      }
    }

    priority_queue<SumPair> sum_pairs;
    for (int num1 : nums1) {
      for (int num2 : nums2) {
        if (num1 + num2 > right) {
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
    int count_sum = 0;
    for (int num1 : nums1) {
      auto it = upper_bound(nums2.begin(), nums2.end(), num - num1);
      if (it == nums2.end()) {
        count_sum += nums2.size();
        if (count_sum > limit) {
          return limit;
        }
        continue;
      }
      int count = it - nums2.begin();
      count_sum += count;
    }
    return count_sum;
  }
};
