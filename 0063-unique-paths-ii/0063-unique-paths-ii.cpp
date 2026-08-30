class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        vector<int> prev(n);

        for (int i = 0; i < m; i++) {
            vector<int> curr(n);
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j]) {
                    curr[j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) {
                    curr[j] = 1;
                    continue;
                }
                int top = 0, left = 0;
                if (i > 0)
                    top = prev[j];
                if (j > 0)
                    left = curr[j - 1];
                curr[j] = top + left;
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};