class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> maximumRobbedMoney(nums.size(), 0);
        maximumRobbedMoney[0] = nums[0];
        maximumRobbedMoney[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            maximumRobbedMoney[i] = max(maximumRobbedMoney[i - 1], maximumRobbedMoney[i - 2] + nums[i]);
        }
        return maximumRobbedMoney.back();
    }
};
