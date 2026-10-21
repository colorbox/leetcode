/*
overflow対策のために負の値が来た時に特殊処理を入れている。
*/
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }

        if (n < 0) {
            return 1.0 / myPow(x, -(n + 1)) / x;
        }

        double half_result = myPow(x, n / 2);
        double full_result = half_result * half_result;
        if (n % 2 == 1) {
            full_result *= x;
        }
        return full_result;
    }
};
