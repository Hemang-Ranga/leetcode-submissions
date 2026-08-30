class Solution {
public:
    int uniquePaths(int m, int n) {
        // space optimized version
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // old dp[j] is top, dp[j-1] is left
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};