class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(), i=0;
        vector<int> ans;
        map<int,int> m;
        for(i=0; i<n; i++){
            if(m.find(target-nums[i]) == m.end()) m.insert({nums[i], i});
            else{
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};