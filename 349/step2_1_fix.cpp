class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> num_to_count;
    for (int num : nums1) {
      num_to_count[num]++;
    }
    vector<int> intersected_nums;
    for(int num : nums2) {
      if (num_to_count[num] > 0) {
        intersected_nums.push_back(num);
        num_to_count[num] = 0;
      }
    }
    return intersected_nums;
  }
};
