class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> unique_nums;
    for (int num : nums1) {
      unique_nums.insert(num);
    }
    vector<int> intersected_nums;
    for (int num : nums2) {
      if (unique_nums.contains(num)) {
        intersected_nums.push_back(num);
        unique_nums.erase(num);
      }
    }
    return intersected_nums;
  }
};
