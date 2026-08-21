class Solution {
public:
    void solve(int n, int k, int ind, vector<int>& curr,
               vector<vector<int>>& ans) {
        if (k == 0) {
            if (n == 0)
                ans.push_back(curr);
            return;
        }
        for (int i = ind + 1; i <= 9; i++) {
            if (i > n)
                break;
            curr.push_back(i);
            solve(n - i, k - 1, i, curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> ans;
        solve(n, k, 0, curr, ans);
        return ans;
    }
};