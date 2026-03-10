class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        vector<vector<int>> pathCount(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        pathCount[0][0] = 1;
        for (int i = 0; i < pathCount.size(); ++i) {
            for (int j = 0; j < pathCount[0].size(); ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                if (i > 0) {
                    pathCount[i][j] += pathCount[i - 1][j];
                }
                if (j > 0) {
                    pathCount[i][j] += pathCount[i][j - 1];
                }
            }
        }
        return pathCount.back().back();
    }
};
