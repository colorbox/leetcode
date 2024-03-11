class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numMap;

        int index, currentTargetNum;
        for(index = 0; index < nums.size(); index++){
            currentTargetNum = target - nums[index];
            if(numMap.find(currentTargetNum) != numMap.end()){
                break;
            }

            numMap[nums[index]] = index;
        }

        return { index, numMap[currentTargetNum] };
    }
};
