/*
二つに分割したもののうち、単調増加の側から探索し、なければ反対を探索する、という方式を他の方のPRを見ていて興味深かったので実装。
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid;
                } else {
                    left = mid;
                }
            } else {
                if (nums[mid] <= target && target <= nums[right - 1]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
        }
        if (nums[left] != target) {
            return -1;
        }
        return left;
    }
};
