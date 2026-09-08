class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i: nums){
            sum += i;
        }
        if(sum&1) return false;
        int target = sum/2;

        vector<int> prev(target+1);
        prev[0] = 1;
        for(int i = n-1; i >= 0; i--){
            vector<int> curr(target+1);
            for(int k = 0; k <= target; k++){
                bool take = false;
                if(k >= nums[i]) take = prev[k - nums[i]];
                bool notTake = prev[k];
                curr[k] = take || notTake;
            }
            prev=curr;
        }
        return prev[target];
    }
};