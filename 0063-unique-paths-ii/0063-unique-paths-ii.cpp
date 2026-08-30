class Solution {
public:
    int f(int r, int c, vector<vector<int>>& obstacleGrid,
          vector<vector<int>>& dp) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (r == 0 && c == 0)
            return 1;
        if (r < 0 || c < 0 || obstacleGrid[r][c] == 1)
            return 0;
        if (dp[r][c] != -1)
            return dp[r][c];
        if (r > 0 && c > 0 && obstacleGrid[r - 1][c] == 1 &&
            obstacleGrid[r][c - 1] == 1)
            return 0;
        if (r > 0 && obstacleGrid[r - 1][c] == 1)
            return dp[r][c] = f(r, c - 1, obstacleGrid, dp);
        if (c > 0 && obstacleGrid[r][c - 1] == 1)
            return dp[r][c] = f(r - 1, c, obstacleGrid, dp);
        return dp[r][c] = f(r - 1, c, obstacleGrid, dp) +
                          f(r, c - 1, obstacleGrid, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, obstacleGrid, dp);
    }
};