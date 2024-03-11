class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numMap;
        for(int index = 0; index < nums.size(); index++){
            int numToFind = target - nums[index];
            if(numMap.find(numToFind) != numMap.end()){
                return { index, numMap[numToFind] };
            }
            numMap[nums[index]] = index;
        }

        return {};
    }
};
