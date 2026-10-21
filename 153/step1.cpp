/*
14:48

indexと配列の中身を取り違えてしまってバグらせてしまい、時間をロスした。


*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums[0] < nums.back()) {
            return nums[0];
        }
        int left = 0;
        int right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return nums[right];
    }
};
