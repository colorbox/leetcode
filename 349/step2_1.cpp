/*
mapで書き直したパターン
単一のmapでカウントできるのでsetを利用するstepqよりもシンプルになった
*/
class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> nums_count;
    for (int num : nums1) {
      if (nums_count[num] == 1) {
        continue;
      }
      nums_count[num]++;
    }
    for (int num : nums2) {
      if (nums_count[num] != 1) {
        continue;
      }
      nums_count[num]++;
    }
    vector<int> intersected_nums;
    for (auto [num, count] : nums_count) {
      if (count == 2) {
        intersected_nums.push_back(num);
      }
    }
    return intersected_nums;
  }
};
