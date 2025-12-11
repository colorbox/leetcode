class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> step_count(m, vector<int>(n, 0));
    step_count[0][0] = 1;
    for (int row = 0; row < m; ++row) {
        for (int col = 0; col < n; ++col) {
            if (col == 0 && row == 0) {
                continue;
            }
            if (row > 0) {
                step_count[row][col] += step_count[row - 1][col];
            }
            if (col > 0) {
                step_count[row][col] += step_count[row][col - 1];
            }         
        }
    }
    return step_count[m - 1][n - 1];
  }
};
