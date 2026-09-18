/*

[left, right]でのパターン。

if (nums[left] <= target && target <= nums[mid]) {
のelseブロックで、leftはtargetを含まない(nums[left] > target)のでmid + 1にする。
この+1は効率化のためだけにつけているわけではない。
midは切り捨てで計算され、左に寄る。
このため、+1を行わないと要素が二つしかない場合に、leftがmidのままになり、無限ループになる。

if (nums[mid] <= target && target <= nums[right]) {
のelseブロックで、rightはtargetを含まない(nums[right] < target)のでmid - 1にする。

left,rightは要素を指し示し、それらを含む区間は未調査であり、その外側にはtargetが存在しない。
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[right]) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
        }
        if (nums[left] != target) {
            return -1;
        }
        return left;
    }
};
