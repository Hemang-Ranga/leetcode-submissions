class Solution {
public:
    int f(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        if (c < 0 || c >= n)
            return INT_MAX;
        if (r == 0)
            return matrix[0][c];
        if (dp[r][c] != INT_MAX)
            return dp[r][c];
        int mini = min({f(r - 1, c - 1, matrix, dp), f(r - 1, c, matrix, dp),
                        f(r - 1, c + 1, matrix, dp)});
        return dp[r][c] = matrix[r][c] + mini;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1)
            return matrix[0][0];
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(f(n - 1, i, matrix, dp), mini);
        }
        return mini;
    }
};