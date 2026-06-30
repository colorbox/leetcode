/*
Solve Time: 18:45

Time Complexity: O(n)
Space Complexity: O(n)

ある程度の方針は最初に建てられたが、正確なコードに落とし込む過程でミスを連発して時間がかかってしまった。
最後の家を盗むかどうかの判定に、最初の家を盗んだかどうかの記録が必要になるので、2通りの配列を用意してそこで管理する。

*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1){
            return nums.front();
        }

        if (nums.size() == 2){
            return max(nums[0], nums[1]);
        }

        vector<int>maxRobbedMoneyWithFirstRobbed(nums.size(), 0);
        maxRobbedMoneyWithFirstRobbed[0] = nums[0];
        maxRobbedMoneyWithFirstRobbed[1] = nums[0];
        vector<int>maxRobbedMoneyWithoutFirstRobbed(nums.size(), 0);
        maxRobbedMoneyWithoutFirstRobbed[1] = nums[1];

        for (int i = 2; i < nums.size(); ++i) {
            if (i < nums.size() - 1) {
                maxRobbedMoneyWithFirstRobbed[i] = max(maxRobbedMoneyWithFirstRobbed[i - 1], maxRobbedMoneyWithFirstRobbed[i - 2] + nums[i]);
            } else {
                maxRobbedMoneyWithFirstRobbed[i] = maxRobbedMoneyWithFirstRobbed[i - 1];
            }

            maxRobbedMoneyWithoutFirstRobbed[i] = max(maxRobbedMoneyWithoutFirstRobbed[i - 1], maxRobbedMoneyWithoutFirstRobbed[i - 2] + nums[i]);
        }

        return max(maxRobbedMoneyWithoutFirstRobbed.back(), maxRobbedMoneyWithFirstRobbed.back());

    }
};
