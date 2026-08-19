class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int> curr,
               int ind) {
        if (ind >= nums.size()) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[ind]);
        solve(nums, ans, curr, ind + 1);
        curr.pop_back();
        solve(nums, ans, curr, ind + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        int ind = 0;
        solve(nums, ans, curr, ind);
        return ans;
    }
};