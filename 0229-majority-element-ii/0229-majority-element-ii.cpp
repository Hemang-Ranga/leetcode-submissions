class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        for(auto itr : m){
            if(itr.second>n/3) ans.push_back(itr.first);
        }
        return ans;
    }
};