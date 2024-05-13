/*
## 解くのに要した時間

07:01

## 計算量

O(logN)

## 思考の流れ

線形探索だと明らかに入力が大きい。
二分探索することを考える。
Good/Badの境界部分を探すと考える
left=false
right=true
になるような二分探索を書きかけるが、
https://github.com/colorbox/leetcode/pull/10#discussion_r1551560196
での指摘を思い出して修正
この場合境界の位置によってはleft=trueとなる場合もあるので、leftの状態も調べてreturn するようにした。
*/
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (right-left > 1) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (isBadVersion(left)) {
            return left;
        } else {
            return right;
        }
    }
};
