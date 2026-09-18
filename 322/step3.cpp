class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> min_coins(amount + 1, numeric_limits<int>::max());
        min_coins[0] = 0;
        for (int to_price = 1; to_price <= amount; ++to_price) {
            for (const int coin : coins) {
                int from_price = to_price - coin;
                if (from_price < 0) {
                    continue;
                }
                if (min_coins[from_price] == numeric_limits<int>::max()) {
                    continue;
                }
                min_coins[to_price] = min(min_coins[from_price] + 1, min_coins[to_price]);
            }
        }
        if (min_coins.back() == numeric_limits<int>::max()) {
            return -1;
        }
        return min_coins.back();
    }
};
