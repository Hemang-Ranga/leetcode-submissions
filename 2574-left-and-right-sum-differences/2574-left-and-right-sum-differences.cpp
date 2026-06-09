class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size(), lsum=0, rsum=0;
        vector<int> left(n), right(n), ans(n);
        for(int i=0; i<n; i++){
            left[i]=lsum;
            right[n-i-1]=rsum;
            lsum+=nums[i];
            rsum+=nums[n-1-i];
        }
        for(int i=0; i<n; i++){
            ans[i]=abs(left[i]-right[i]);
        }
        return ans;
    }
};