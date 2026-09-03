class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total_subsets = 1<<n; //2^n
        vector<vector<int>> ans;
        for(int mask=0; mask<total_subsets; mask++){
            vector<int> curr;
            for(int i=0; i<n; i++){
                if(mask & (1<<i)) curr.push_back(nums[i]);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};