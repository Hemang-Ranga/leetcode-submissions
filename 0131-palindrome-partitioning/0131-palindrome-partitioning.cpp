class Solution {
private:
    bool isPalin(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
    void solve(const string& s, int ind, vector<string>& curr,
               vector<vector<string>>& ans) {
        if (ind >= s.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = ind + 1; i <= s.size(); i++) {
            if (isPalin(s, ind, i - 1)) {
                curr.push_back(s.substr(ind, i - ind));
                solve(s, i, curr, ans);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        int ind = 0;
        solve(s, ind, curr, ans);
        return ans;
    }
};