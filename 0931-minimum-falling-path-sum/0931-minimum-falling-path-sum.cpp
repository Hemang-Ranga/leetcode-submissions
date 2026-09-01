class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1)
            return matrix[0][0];
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dp[0] = matrix[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int left = INT_MAX;
                if (j > 0)
                    left = dp[i - 1][j - 1];

                int middle = dp[i - 1][j];

                int right = INT_MAX;
                if (j < n - 1)
                    right = dp[i - 1][j + 1];

                dp[i][j] = matrix[i][j] + min({left, middle, right});
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};