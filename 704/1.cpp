class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (target < nums[0] || nums[nums.size()-1] < target) { return -1; }

        int l = -1;
        int r = nums.size();

        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid;
            } else {
                r = mid;
            }
        }

        if (nums[r] == target) { return r; }

        return -1;
    }

};
