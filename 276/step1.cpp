/*

Solve Time: 20:00

Time: O(n)
Space: O(n)

色の数で混乱しかけたが
- 前に使った色と同じ色でなければよいので、色の数の多さはそこまで影響がない
- 1枚塗るか2枚塗るというのを配列を1,2進むで表現可能
の二点に気づいたら割とすんなりできた
kを入れる位置に少し悩んだが、なんとかパスした
*/

class Solution {
public:
  int numWays(int n, int k) {
    if (k == 1 && n >= 3) { 
      return 0;
    }
    if (n == 1 || k == 1) {
      return k;
    }
    vector<long> dp(n + 1);
    dp[1] = k;
    dp[2] = k;
    for (int i = 2; i <= n; ++i) {
      dp[i] += dp[i - 1] * (k - 1);
      if (i >= 2) {
        dp[i] += dp[i - 2] * (k - 1);
      }
    }
    return dp[n];
  }
};
