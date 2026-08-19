class Solution {
public:
    void solve(vector<int>& arr, int k, vector<int>& curr, int ind,
               vector<vector<int>>& ans) {
        if (k == 0) {
            ans.push_back(curr);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > k)
                break;
            curr.push_back(arr[i]);
            solve(arr, k - arr[i], curr, i + 1, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        vector<vector<int>> ans;
        int ind = 0;
        solve(candidates, target, curr, ind, ans);
        return ans;
    }
};