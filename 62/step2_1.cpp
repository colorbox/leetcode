/*
変数名を微修正
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        grid[0][0]=1;

        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (x > 0) {
                    grid[y][x] += grid[y][x - 1];
                }
                if(y > 0) {
                    grid[y][x] += grid[y-1][x];
                }
            }
        }
        return grid[m-1][n-1];
    }
};
