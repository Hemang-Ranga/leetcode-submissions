class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;
        int n=nums.size();
        int left=0, ans=0, p=1;
        for(int right=0; right<n; right++){
            p*=nums[right];
            while(p>=k && left<=right){
                p/=nums[left];
                left++;
            }
            ans += right-left+1;
        }
        return ans;
    }
};