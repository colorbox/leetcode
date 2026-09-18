/*
Time: 11:13

Time Complexity: O(log(n))
Space Complexity: O(n)

targetがnumsの中に存在しないパターンの対処に少し時間がかかってしまった。
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                right = mid;
                continue;
            }
            if (nums[mid] < target) {
                left = mid;
                continue;
            }
        }
        if (target <= nums[left]) {
            return left;
        } else {
            return right;
        }
    }
};
