class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> increasing_sequence;
        for (auto num: nums) {
            auto it = lower_bound(increasing_sequence.begin(), increasing_sequence.end(), num);
            if (it == increasing_sequence.end()) {
                increasing_sequence.push_back(num);
            } else {
                *it = num;
            }
        }
        return increasing_sequence.size();
    }
};
