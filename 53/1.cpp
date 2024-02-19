class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];

        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                ret = max(ret, sumSubarray(nums, i, j));
            }
        }
        return ret;
    }

    int sumSubarray(vector<int>& nums, int l, int r){
        int ret = 0;
        for(int i=l; i<=r; i++){
            ret += nums[i];
        }
        return ret;
    }
};
