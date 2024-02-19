class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        vector<int> cums = {0};
        for(int i=0; i<nums.size(); i++){
            cums.push_back(cums[i]+nums[i]);
        }

        int currentMinCum = cums[0];
        for(int i=0; i<nums.size(); i++){
            currentMinCum = min(currentMinCum, cums[i]);
            ret = max(ret, cums[i+1] - currentMinCum);
        }
        return ret;
    }
};
