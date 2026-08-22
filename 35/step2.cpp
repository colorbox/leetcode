/*
Time : 03:18

他の人のコードとそのレビューを読むことでstep1は認識すべきleft,rightの不変条件をよく理解できていないまま書いていたことがわかった。
step1のコードはkeft,rightの不変条件などの理解が不十分なまま書かれた結果歪な分岐が末尾に出現している。
二分探索の理解が少し深まった。

*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
