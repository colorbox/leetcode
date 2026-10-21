class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        if (n < 0) {
            return 1.0 / myPow(x, -(n + 1)) / x;
        }
        int64_t exponent = n;
        double half_powered = myPow(x, exponent / 2);
        double full_powered = half_powered * half_powered;
        if (exponent % 2 == 1) {
            return full_powered * x;
        }
        return full_powered;
    }
};
