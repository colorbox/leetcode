class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numMap;
        int currentOther, index;

        for(index = 0; index < nums.size(); index++){
            currentOther = target - nums[index];
            if(numMap.find(currentOther) != numMap.end()){
                break;
            }
            numMap[nums[index]] = index;
        }

        return { index, numMap[currentOther] };
    }
};
