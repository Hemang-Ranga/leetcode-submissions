class Solution {
public:
    void solve(int n, string curr, int open, int close, vector<string>& ans) {
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        if (open < n) {
            curr += "(";
            open++;
            solve(n, curr, open, close, ans);
            curr.pop_back();
            open--;
        }
        if (close < open) {
            curr += ")";
            close++;
            solve(n, curr, open, close, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        int open = 0, close = 0;
        solve(n, curr, open, close, ans);
        return ans;
    }
};