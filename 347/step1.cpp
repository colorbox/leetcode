/*
20:14

Space: O(N)
Time:  O(NlogN)

出現頻度の高い順にk個の要素を返す。
出現頻度をカウント、カウント部分を取り出してソートしてk個残す。
残したカウントと合致する要素を使ってvector<int>を作成して返す。

*/
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> counter;
    for (int num : nums) {
      if (!counter.contains(num)) {
        counter[num] = 0;
      }
      counter[num]++;
    }
    multiset<int> sorted_counts;
    for (auto pair : counter) {
      sorted_counts.insert(pair.second);
    }
    auto it = sorted_counts.begin();
    for (int i = 0; i < sorted_counts.size() - k; i++) {
      it++;
    }
    sorted_counts.erase(sorted_counts.begin(), it);

    vector<int> answer;
    for (auto pair : counter) {
      if (sorted_counts.contains(pair.second)) {
        answer.push_back(pair.first);
      }
    }
    return answer;
  }
};
