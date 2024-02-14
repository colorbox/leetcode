class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentMax = 0;

        for(int i = 0; i < nums.size(); i++){
            currentMax += nums[i];

            maxSum = max(maxSum, currentMax);

            currentMax = max(currentMax, 0);
        }

        return maxSum;
    }
};
