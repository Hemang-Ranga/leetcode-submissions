class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int lower=0, greater=n-1;
        vector<int> ans(n,pivot);
        for(int i=0; i<n; i++){
            if(nums[i]<pivot) ans[lower++]=nums[i];
            if(nums[n-i-1]>pivot) ans[greater--]=nums[n-i-1];
        }
        return ans;
    }
};