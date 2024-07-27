/*
Time(20:43)

KthLargest
Space: O(N)
Time: O(NlogN)

Add
Space: O(1)
Time: O(N)

毎回ソートをすると間違いなく時間が足りなくなるのでそうしないように実装する必要がある。
ソート済みの配列の適切な位置に挿入することでaddを実装できると思ったのでそのように実装。

*/
class KthLargest {
  vector<int> sorted;
  int target;
public:
  KthLargest(int k, vector<int>& nums) {
    target = k;
    for (int num: nums) {
      sorted.push_back(num);
    }
    sort(sorted.begin(), sorted.end());
  }
    
  int add(int val) {
    auto it = lower_bound(sorted.begin(), sorted.end(), val);
    sorted.insert(it, val);
    return sorted[sorted.size() - target];
  }
};
