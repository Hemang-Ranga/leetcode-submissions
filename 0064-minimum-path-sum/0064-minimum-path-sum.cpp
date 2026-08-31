class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n);
        for (int i = 0; i < m; i++) {
            vector<int> curr(n);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    curr[j] = grid[i][j];
                    continue;
                }
                int left = INT_MAX;
                int top = INT_MAX;
                if (i > 0)
                    top = prev[j];
                if (j > 0)
                    left = curr[j - 1];
                curr[j] = min(top, left) + grid[i][j];
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};