class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) { return 0; }
        if (obstacleGrid.back().back() == 1) { return 0; }

        vector<vector<int>> pathCounter(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));

        pathCounter[0][0] = 1;
        for (int y = 0; y < obstacleGrid.size(); ++y) {
            for (int x = 0; x < obstacleGrid[0].size(); ++x) {
                if (obstacleGrid[y][x] == 1) {
                    continue;
                }
                if (x > 0) {
                    pathCounter[y][x] += pathCounter[y][x - 1];
                }
                if (y > 0) {
                    pathCounter[y][x] += pathCounter[y - 1][x];
                }
            }
        }
        return pathCounter.back().back();
    }
};
