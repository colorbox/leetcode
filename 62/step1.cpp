// Time: 07:01

// Time Space: O(m * n)
// Memory Space: O(m * n)

/*
上と左の経路数をそのまま合計していき、それを繰り返すというのを思いつけたのでそのまま実装
変数名が若干分かりづらいので、grid、というコンテキストに適した名前にするとよさそう
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        grid[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) {
                    grid[i][j] += grid[i-1][j];
                }
                if (j > 0) {
                    grid[i][j] += grid[i][j-1];
                }
            }
        }
        return grid[m-1][n-1];
    }
};
