class Solution {
public:
    int f(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (r == 0 && c == 0)
            return grid[0][0];
        if (r < 0 || c < 0)
            return INT_MAX;
        if (dp[r][c] != -1)
            return dp[r][c];
        int top = f(r - 1, c, grid, dp);
        int left = f(r, c - 1, grid, dp);
        return dp[r][c] = grid[r][c] + min(top, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, grid, dp);
    }
};