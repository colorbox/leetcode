/*
Time: O(N log N + M log M)
Space: O(N + M)

nums1.size() == N
nums2.size() == M 

２つのnumsをソートしてマージソートっぽくする手法
https://github.com/gcc-mirror/gcc/blob/8762bb1b004c442b8dbb22a6d9eb0b7da4a3e59f/libstdc%2B%2B-v3/include/bits/stl_algo.h#L5208-L5230
*/
class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> intersected_nums;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] < nums2[j]) {
        i++;
      } else if (nums2[j] < nums1[i]) {
        j++;
      } else {
        if (intersected_nums.empty() || intersected_nums.back() != nums1[i]) {
          intersected_nums.push_back(nums1[i]);
        }
        i++;
        j++;
      }
    }
    return intersected_nums;
  }
};
