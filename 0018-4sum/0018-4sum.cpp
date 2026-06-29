class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n-3; i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            long long sum3 = (long long)target-nums[i];
            for(int j=i+1; j<n-2; j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1, l=n-1;
                long long sum2=sum3-(long long)nums[j];
                while(k<l){
                    int s = nums[k]+nums[l];
                    if(s<sum2) k++;
                    else if(s>sum2) l--;
                    else{
                        vector<int> a;
                        a={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(a);
                        k++;
                        l--;
                        while(k<l && nums[k-1]==nums[k]) k++;
                        while(l>k && nums[l]==nums[l+1]) l--;
                    }
                }
            }
        }
        return ans;
    }
};