class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), cnt=0;
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=0; i<n; i++){
            cnt++;
            if((i<n-1 && nums[i]!=nums[i+1]) || i==n-1){
                if(cnt>n/3) ans.push_back(nums[i]);
                cnt=0;
            }
        }
        return ans;
    }
};