class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        vector<int> cums = {};
        for(int i=0; i<nums.size(); i++){
            sum = cums[i]+nums[i];
            cums.push_back(cum);
        }

        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                ret = max(ret, sumSubarray(cums, i, j));
            }
        }
        return ret;
    }

    int sumSubarray(vector<int>& cums, int l, int r){
        return cums[r+1] - cums[l];
    }
};
