/*
単一の配列で実行するのを試す
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> step_counter(n, 0);
        step_counter[0] = 1; 

        for (int y = 0; y < m; ++y) {
            for(int x = 1; x < n; ++x) {
                int step = 0;
                if (y > 0) {
                    step += step_counter[x];
                }
                if (x > 0) {
                    step += step_counter[x - 1];
                }
                step_counter[x] = step;
            }
        }
        return step_counter.back();
    }
};
