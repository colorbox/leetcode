/*
`std::set_intersection`を使うパターン

Time : O(N log N + M log M)
Space: O(N + M)

nums1.size() == N
nums2.size() == M 
*/
class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> intersected_nums;
    set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), inserter(intersected_nums, intersected_nums.end()));
    auto it = unique(intersected_nums.begin(), intersected_nums.end());
    intersected_nums.erase(it, intersected_nums.end());
    return intersected_nums;
  }
};
