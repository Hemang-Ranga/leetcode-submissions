class Solution {
public:
    int f(int i, int iprev, vector<int>& arr, vector<vector<int>>& dp){
        if(i==arr.size()) return 0;
        if(dp[i][iprev+1]!=-1) return dp[i][iprev+1];
        int skip = f(i+1, iprev, arr, dp);
        int take = 0;
        if(iprev==-1 || arr[i]>arr[iprev]) take = 1+f(i+1, i, arr, dp);
        return dp[i][iprev+1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(0,-1,nums,dp);
    }
};