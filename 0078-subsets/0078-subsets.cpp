class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int> curr,
               int ind) {
        ans.push_back(curr);
        if (ind >= nums.size())
            return;
        for (int i = ind; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            solve(nums, ans, curr, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        int ind = 0;
        solve(nums, ans, curr, ind);
        return ans;
    }
};