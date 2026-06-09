class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int lsum=0, rsum=accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            rsum-=nums[i];
            ans[i] = (rsum>=lsum) ? rsum-lsum : lsum-rsum;
            lsum+=nums[i];
        }
        return ans;
    }
};