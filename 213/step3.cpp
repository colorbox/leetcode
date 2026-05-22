/*
https://github.com/5ky7/arai60/pull/37
を参考にstd::spanを使用。
vector<int>をコピーせずにいい感じに渡す方法を探したらこのPRに辿り着いた。
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums.front();
        }

        std::span<int> with_first_house(nums.begin(), nums.end() - 1);
        std::span<int> without_first_house(nums.begin() + 1, nums.end());
        return max(rob_linear(with_first_house), rob_linear(without_first_house));
    }

private:
    int rob_linear(std::span<int>& nums) {
        if (nums.size() == 1) {
            return nums.front();
        }
        int robbed_2_previous_max_money = nums[0];
        int robbed_previous_max_money = nums[1];
        for(int i = 2; i < nums.size(); ++i) {
            int max_money = max(robbed_2_previous_max_money + nums[i], robbed_previous_max_money);
            robbed_2_previous_max_money = max(robbed_2_previous_max_money, robbed_previous_max_money);
            robbed_previous_max_money = max_money;
        }
        return max(robbed_previous_max_money, robbed_2_previous_max_money);
    }
};
