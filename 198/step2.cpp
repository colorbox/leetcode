class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> maximumBenefit(nums.size(), 0);
        maximumBenefit[0] = nums[0];
        for (int i = 1; i < maximumBenefit.size(); ++i) {
            int benefit = nums[i];
            if (i >= 2) {
                benefit += maximumBenefit[i - 2];
            }
            maximumBenefit[i] = max(benefit, maximumBenefit[i - 1]);
        }
        return maximumBenefit.back();
    }
};
