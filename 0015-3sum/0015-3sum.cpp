class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int target = -nums[i];
            int j=i+1, k=n-1;
            while(j<k){
                if(nums[j]+nums[k]==target){
                    vector<int> a;
                    a={nums[i], nums[j], nums[k]};
                    st.insert(a);
                    j++;
                }
                else if(nums[j]+nums[k]<target) j++;
                else k--;
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};