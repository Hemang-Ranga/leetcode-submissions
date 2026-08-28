class Solution {
public:
    // f(i) -> max robbery till index i, (from 0 to i)
    int f(int i, vector<int>& nums, vector<int>& dp) {
        if (i < 0)
            return 0;

        if (dp[i] != -1)
            return dp[i];
        // take
        int a = nums[i] + f(i - 2, nums, dp);
        // don't take
        int b = f(i - 1, nums, dp);
        return dp[i] = max(a, b);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n - 1, nums, dp); // max robbery from 0 to n-1
    }
};