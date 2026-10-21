/*
bit方式
最初にx = 1.0 / xとしてしまうとnが大きい数値の時に誤差が拡大してしまう。
逆数計算は最後にまとめて行う。
*/
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            return 1.0 / powHelper(x, -1.0 * n);
        }
        return powHelper(x, (int64_t) n);         
    }

private:
    double powHelper(double x, int64_t n) {
        if (n == 0) {
            return 1.0;
        }
        int64_t exponent = n;
        double powering_num = x;
        double powered_num = 1.0;
        while (exponent) {
            if (exponent & 1) {
                powered_num *= powering_num;
            }
            powering_num *= powering_num;
            exponent = exponent >> 1;
        }
        return powered_num;
    }
};
