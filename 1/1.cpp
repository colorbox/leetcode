class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numMap;

        int index = 0;
        int currentTargetNum = 0;
        for(; index < nums.size(); index++){
            currentTargetNum = target - nums[index];
            if(numMap.find(currentTargetNum) != numMap.end() && index != numMap[currentTargetNum]){
                break;
            }

            numMap[nums[index]] = index;
        }

        return { index, numMap[currentTargetNum] };
    }
};
