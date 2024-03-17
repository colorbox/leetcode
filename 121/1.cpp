class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> minPricesFromStart;
        vector<int> maxPricesFromEnd;

        int minPrice = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            minPricesFromStart.push_back(minPrice);
        }
        int maxPrice = -1;
        for(int i = prices.size()-1; i >= 0; i--){
            maxPrice = max(maxPrice, prices[i]);
            maxPricesFromEnd.push_back(maxPrice);
        }
        reverse(maxPricesFromEnd.begin(), maxPricesFromEnd.end());

        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++){
            int currentProfit = maxPricesFromEnd[i] - minPricesFromStart[i];
            maxProfit = max(maxProfit, currentProfit);
        }
        return maxProfit;
    }
};
