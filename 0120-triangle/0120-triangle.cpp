class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 1)
            return triangle[0][0];
        vector<int> prev = triangle[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(i + 1);
            for (int j = 0; j < i + 1; j++) {
                int mini = min(prev[j], prev[j + 1]);
                curr[j] = triangle[i][j] + mini;
            }
            prev = curr;
        }
        return prev[0];
    }
};