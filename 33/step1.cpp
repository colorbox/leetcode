/*
Time: 15:27

Time Complexity: O(log(n))
Space Complexity: O(1)

*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min_index, max_index;
        if (nums[0] < nums.back()) {
            min_index = 0;
            max_index = nums.size() - 1;
        } else {
            int left = 0;
            int right = nums.size() - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] > nums.back()) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            min_index = left;
            max_index = (left - 1) % nums.size();
        }

        if (nums[max_index] < target || nums[min_index] > target) {
            return -1;
        }

        int left,right;
        if (nums[0] <= target && target <= nums[max_index]) {
            left = 0;
            right = max_index;
        } else {
            left = min_index;
            right = nums.size() - 1;
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (nums[left] != target) {
            return -1;
        }
        return left;


    }
};
