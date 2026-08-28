class Solution {
public:
    int f(int i, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        if (i >= n - 2)
            return dp[i] = nums[i];

        if (dp[i] != -1)
            return dp[i];

        int cost = nums[i];
        int maximum = INT_MIN;
        for (int j = i + 2; j < n; j++) {
            maximum = max(f(j, nums, dp), maximum);
        }
        return dp[i] = cost + maximum;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        vector<int> dp(n, -1);
        int x = f(0, nums, dp);
        int y = f(1, nums, dp);
        return max(x, y);
    }
};