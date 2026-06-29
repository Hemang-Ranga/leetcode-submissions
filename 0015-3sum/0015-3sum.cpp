class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            int j=i+1, k=n-1;
            while(j<k){
                if(nums[j]+nums[k] == -nums[i]){
                    vector<int> a;
                    a={nums[i], nums[j], nums[k]};
                    ans.push_back(a);
                    j++;
                    k--;
                    while(j<k && nums[j-1]==nums[j]) j++;
                    while(k>j && nums[k]==nums[k+1])  k--;  
                }
                else if(nums[j]+nums[k] < -nums[i]) j++;
                else k--;
            }
        }
        return ans;
    }
};