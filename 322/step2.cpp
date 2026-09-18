/*
DPの方向を変えてオーバーフローしないようにした。
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> coin_nums(amount + 1, numeric_limits<int>::max());
        coin_nums[0] = 0;
        for (int to_coins = 1; to_coins <= amount; ++to_coins) {
            for (const int coin : coins) {
                int from_coins = to_coins - coin;
                if (from_coins < 0) {
                    continue;
                }
                if (coin_nums[from_coins] == numeric_limits<int>::max()) {
                    continue;
                }
                coin_nums[to_coins] = min(coin_nums[from_coins] + 1, coin_nums[to_coins]);
            }
        }
        if (coin_nums.back() == numeric_limits<int>::max()) {
            return -1;
        }
        return coin_nums.back();
    }
};
