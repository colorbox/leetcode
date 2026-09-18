/*

株を持っている状態と持っていない状態に分けて、各状態で利益の多い値で更新していく方式。
最初DPの構造が見えていなかったので、LLMと壁打ちしてその辺りの構造を理解した。

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit_with_stock = numeric_limits<int>::min();
        int max_profit_without_stock = 0;
        for (int i = 0; i < prices.size(); ++i) {
            int tmp_max_profit_with_stock = max(max_profit_with_stock, max_profit_without_stock - prices[i]);
            max_profit_without_stock = max(max_profit_without_stock, max_profit_with_stock + prices[i]);
            max_profit_with_stock = tmp_max_profit_with_stock;
        }
        return max(max_profit_with_stock, max_profit_without_stock);
    }
};
