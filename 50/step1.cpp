/*
考え方は構築できたが、エッジケースを処理できず時間をかけすぎてしまったので解答を見た
浮動小数の計算による誤差やオーバーフローなどを考慮しきれていない状態だった

Time Complexity: O(log n)
Space Complexity: O(1)

CPU速度を1GHzとして、C++は１秒間に10^9回の処理が可能であることから1ms未満で完了するものと思われる
*/
class Solution {
public:
    double myPow(double x, int n) {
        return RecursiveMyPow(x, (long long)n);
    }

private:
    double RecursiveMyPow(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }
        if (n == 1) {
            return x;
        }
        if (n < 0) {
            return 1.0 / RecursiveMyPow(x, -1.0 * n);
        }

        double half_result = RecursiveMyPow(x, n / 2);
        double full_result = half_result * half_result;
        if (n % 2 == 1) {
            full_result *= x;
        }
        return full_result;
    }
};
