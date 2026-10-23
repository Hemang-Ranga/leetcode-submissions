class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> prev_dp(n+1);
        //here j = iprev - 1
        for(int i=n-1; i>=0; i--){
            vector<int> currdp(n+1);
            for(int j=0; j<=i;j++){
                int skip = prev_dp[j];
                int take = 0;
                if(j==0 || nums[i]>nums[j-1]){
                    take = 1+prev_dp[i+1];
                }
                currdp[j] = max(skip, take);
            }
            prev_dp = currdp;
        }
        return prev_dp[0];
    }
};