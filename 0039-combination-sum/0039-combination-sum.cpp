class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans,
               vector<int>& curr, int i) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (target < 0 || i >= candidates.size())
            return;

        curr.push_back(candidates[i]);
        solve(candidates, target - candidates[i], ans, curr, i);
        curr.pop_back();

        solve(candidates, target, ans, curr, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int i = 0, sum = 0;
        solve(candidates, target, ans, curr, i);
        return ans;
    }
};