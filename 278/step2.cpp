/*
他の人のコードや解説を見て完了したコード
二分探索のwhileの継続条件部分が効率の良くない形になっていたので修正
二分探索で範囲を狭める時にチェック済みの箇所についても+1/-1で追加で狭めるように修正(https://github.com/colorbox/leetcode/pull/10#discussion_r1551560196)
上記2点の修正後、whileループ後の無駄なチェックをなくせるようになったのでそれらを削除

leftが最初にtrueとなる位置なので、leftを返して良くなる
midの状態は確定しているので、`left = mid + 1`によって、leftに対して未確定の位置を与える。
これによって少しだけ高速化される。

*/
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
