class Solution {
public:
    int f(int r, int c, vector<vector<int>>& triangle,
          vector<vector<int>>& dp) {
        int n = triangle.size();
        if (r == n - 1)
            return dp[r][c] = triangle[r][c];
        if (dp[r][c] != INT_MIN)
            return dp[r][c];
        int a = f(r + 1, c, triangle, dp);
        int b = f(r + 1, c + 1, triangle, dp);
        return dp[r][c] = triangle[r][c] + min(a, b);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 1)
            return triangle[0][0];
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                dp[i].push_back(INT_MIN);
            }
        }
        return f(0, 0, triangle, dp);
    }
};