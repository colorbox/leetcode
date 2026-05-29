class Solution {
public:
  int numWays(int n, int k) {
    if (n == 1) {
      return k;
    }
    if (n == 2) {
      return k * (k - 1) + k;
    }

    int previous_count = k;
    int count = k * (k - 1) + k;
    for (int i = 2; i < n; ++i) {
      int tmp = count;
      count = count * (k - 1) + previous_count * (k - 1);
      previous_count = tmp;
    }
    return count;
  }
};
