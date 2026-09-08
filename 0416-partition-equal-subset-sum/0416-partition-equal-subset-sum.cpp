class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i: nums){
            sum += i;
        }
        if(sum&1) return false;
        int target = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

        dp[n][0] = 1;

        for(int i = n-1; i >= 0; i--){
            for(int k = 0; k <= target; k++){
                bool take = false;
                if(k >= nums[i]) take = dp[i+1][k - nums[i]];
                bool notTake = dp[i+1][k];
                dp[i][k] = take || notTake;
            }
        }
        return dp[0][target];
    }
};