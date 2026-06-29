class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(m.find(target-nums[i]) == m.end()) m[nums[i]]=i;
            else{
                ans={m[target-nums[i]],i};
                return ans;
            }
        }
        return ans;
    }
};