/*
13:25

Time: O(n^2)
Space : O(n)

ひとまず愚直に解く
対象のインデックスに到達するまでの最大長を保持し、その情報を後続で使用する

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> counts(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    counts[i] = max(counts[j] + 1, counts[i]);
                }
            }
        }
        int max_count = 0;
        for (int i = 0; i < counts.size(); ++i) {
            max_count = max(counts[i], max_count);
        }
        return max_count;
    }
};
