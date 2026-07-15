/*

Time Comprexity: O(n * m) (n: amount, m: coinsの長さ)
Space Complexity: O(n)

intでオーバーフローしてしまい、脊髄反射的にlongを使用したがDPの方向を変えればオーバーフローしなさそう
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long> coin_nums(amount + 1, numeric_limits<long>::max());
        coin_nums[0] = 0;
        for (long i = 0; i <= amount; ++i) {
            if (coin_nums[i] == numeric_limits<long>::max()) {
                continue;
            }
            for (const long coin : coins) {
                if (i + coin > amount) {
                    continue;
                }
                coin_nums[i + coin] = min(coin_nums[i] + 1, coin_nums[i + coin]);
            }
        }
        if (coin_nums.back() == numeric_limits<long>::max()) {
            return -1;
        }
        return coin_nums.back();
    }
};
