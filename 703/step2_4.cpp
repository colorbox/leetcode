/*
https://github.com/Ryotaro25/leetcode_first60/pull/9/files#r1619710596
https://discord.com/channels/1084280443945353267/1183683738635346001/1185972070165782688
を参考にmultisetを使用した解法を実装
*/
class KthLargest {
private:
  multiset<int> s;
  int capacity;
public:
  KthLargest(int k, vector<int>& nums): capacity(k) {
    for (int num: nums) {
      s.insert(num);
    }

    while (s.size() > capacity) {
      s.erase(s.begin());
    }
  }
  
  int add(int val) {
    if (s.size() == capacity && val < *s.begin()) {
      return *s.begin();
    }
    s.insert(val);
    if (s.size() > capacity) {
      s.erase(s.begin());
    }
    return *s.begin();
  }
};
