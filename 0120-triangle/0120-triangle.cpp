class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 1)
            return triangle[0][0];
        vector<vector<int>> dp = triangle;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < i + 1; j++) {
                int mini = min(dp[i + 1][j], dp[i + 1][j + 1]);
                dp[i][j] = triangle[i][j] + mini;
            }
        }
        return dp[0][0];
    }
};