/*

2変数 * 2で行うパターン
必要な情報を詰め込んで変数名が長くなってしまっているのが難点
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        if(nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        int maxMoneyTwoPreRobWithFirstRob = nums[0];
        int maxMoneyOnePreRobWithFirstRob = nums[0];

        int maxMoneyTwoPreRobWithoutFirstRob = 0;
        int maxMoneyOnePreRobWithoutFirstRob = nums[1];

        for (int i = 2; i < nums.size(); ++i) {
            if (i < nums.size() - 1){ 
                int maxBenefitWithFirstRob = max(maxMoneyOnePreRobWithFirstRob, maxMoneyTwoPreRobWithFirstRob + nums[i]);
                maxMoneyTwoPreRobWithFirstRob = maxMoneyOnePreRobWithFirstRob;
                maxMoneyOnePreRobWithFirstRob = maxBenefitWithFirstRob;
            }

            int maxBenefitWithoutFirstRob = max(maxMoneyOnePreRobWithoutFirstRob, maxMoneyTwoPreRobWithoutFirstRob + nums[i]);
            maxMoneyTwoPreRobWithoutFirstRob = maxMoneyOnePreRobWithoutFirstRob;
            maxMoneyOnePreRobWithoutFirstRob = maxBenefitWithoutFirstRob;
        }
        return max(maxMoneyOnePreRobWithFirstRob, maxMoneyOnePreRobWithoutFirstRob);
    }
};
