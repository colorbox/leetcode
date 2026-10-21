/*
left: 崖の左側のうち、確認済みの最大インデックス。これより左は、崖の左側であることが確定している。
right: 崖の右側のうち、確認済みの最小インデックス。これより右は、崖の右側であることが確定している。
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums[0] < nums.back() || nums.size() == 1) {
            return nums[0];
        }
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[left] < nums[mid]) {
                left = mid ;
            } else {
                right = mid;
            }
        }
        return nums[left + 1];
    }
};
