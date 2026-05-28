// Solve Time: 10:49
//
// Space Complexity: O(n)
// Time Complexity: O(n)

/*

なんとなく方針をを決めてそのまま実装する
配列を用意して、特定の位置における最大利益、とする。
同日に隣接する箇所は襲えないので、前日の値をそのまま持ってくるか、一昨日の利益に当日の利益を足すか、のどちらかを選ぶ。

benefit += maximumBenefit[i - 2];
とすべき箇所を
benefit += nums[i - 2];
としてしまった

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> maximumBenefit(nums.size(), 0);
        if (nums.size() == 1) {
            return nums[0];
        }
        maximumBenefit[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int benefit = nums[i];
            if (i >= 2) {
                benefit += maximumBenefit[i - 2];
            }
            maximumBenefit[i] = max(benefit, maximumBenefit[i - 1]);
        }
        return maximumBenefit.back();
    }
};
