class Solution {
public:
    int f(int start, int i, vector<int>& nums, vector<int>& dp) {
        if (i < start)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int a = nums[i] + f(start, i - 2, nums, dp);
        int b = f(start, i - 1, nums, dp);
        return dp[i] = max(a, b);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        return max(f(0, n - 2, nums, dp1), f(1, n - 1, nums, dp2));
    }
};