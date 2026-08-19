class Solution {
public:
    void solve(vector<int>& nums, vector<int>& curr, int ind,
               vector<vector<int>>& ans) {
        ans.push_back(curr);
        if (ind >= nums.size())
            return;
        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i] == nums[i - 1])
                continue;
            curr.push_back(nums[i]);
            solve(nums, curr, i + 1, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        int ind = 0;
        solve(nums, curr, ind, ans);
        return ans;
    }
};