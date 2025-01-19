/*
Time: 8:40

Time: O(N log N + M log M)
Space: O(N + M)

nums1.size() == N
nums2.size() == M 
*/
class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> nums1_set;
    for (int num : nums1) {
      if (nums1_set.find(num) != nums1_set.end()) {
        continue;
      }
      nums1_set.insert(num);
    }
    set<int> intersection;
    for (int num : nums2) {
      if (nums1_set.find(num) == nums1_set.end()) {
        continue;
      }
      if (intersection.find(num) != intersection.end()) {
        continue;
      }
      if (nums1_set.find(num) != nums1_set.end()) {
        intersection.insert(num);
      }
    }

    vector<int> answer;
    for (int num : intersection) {
      answer.emplace_back(num);
    }

    return answer;
  }
};
