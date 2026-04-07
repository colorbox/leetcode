// 2変数で行う手法
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums.front();
        }
        int twoPreviousMaximumRobbedMoney = nums[0];
        int previousMaximumRobbedMoney = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            int currentMaximumRobbedMoney = max(previousMaximumRobbedMoney, twoPreviousMaximumRobbedMoney + nums[i]);
            twoPreviousMaximumRobbedMoney = previousMaximumRobbedMoney;
            previousMaximumRobbedMoney = currentMaximumRobbedMoney;
        }
        return previousMaximumRobbedMoney;
    }
};
