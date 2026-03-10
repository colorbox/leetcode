//Time: 15:26
// Space Complexity: O(m*n)
// Time Complexity: O(m*n)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int height = obstacleGrid.size();
        int width = obstacleGrid.front().size();
        vector<vector<int>> step_count(height, vector<int>(width, 0));
        
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        step_count[0][0]=1;

        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if (obstacleGrid[row][col] == 1) {
                    continue;
                }
                if (row == 0 && col == 0) {
                    continue;
                }
                int current_step_count = 0;
                if (row > 0) {
                    current_step_count += step_count[row-1][col];
                }
                if (col > 0) {
                    current_step_count += step_count[row][col-1];
                }
                step_count[row][col] = current_step_count;
            }
        }
        return step_count[height-1][width-1];
    }
};
