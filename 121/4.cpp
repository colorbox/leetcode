class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())abort();
        
        int minPrice = prices[0];
        int currentProfit = 0;
        for(int price: prices) {
            if (price < minPrice) {
                minPrice = price;
            } else {
                currentProfit = max(currentProfit, price - minPrice);
            }
        }

        return currentProfit;
    }
};
