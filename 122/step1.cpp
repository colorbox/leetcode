/*
--:--

Time complexity: O(n)
Space complexity: O(1)

計算ミスをしてしまい、１円でも特になるなら常に売買してよい、という条件を見落としてしまう。
底値で買って最高値で売るを繰り返すというコードを書こうとしたが、いまいちコードに落とし込めなかった。
などのミスによって初見で解けなかったので解説などを見た

全探索→DP→貪欲法という順序を進んでとければ良かったが、DPの構造を見出せなかったのでstep2以降で練習していく
自分の良くない思考の癖みたいなのをLLMとのやり取りの中で見つけられたので次回以降は改善していきたい
ボトムアップで考えず、ひらめきによるショートカットを試みようとする悪癖があり、それが出るとコードが書けなくてハマってしまう。
全探索から考えていけるように練習していく


*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_benefit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                max_benefit += prices[i] - prices[i - 1];
            }
        }
        return max_benefit;
    }
};
