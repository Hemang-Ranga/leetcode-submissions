class Solution {
public:
    void solve(string& digits, int i, string& curr, vector<string>& ans,
               vector<string>& dial) {
        if (i == digits.size()) {
            ans.push_back(curr);
            return;
        }
        for (char c : dial[digits[i] - 48 - 2]) {
            curr.push_back(c);
            solve(digits, i + 1, curr, ans, dial);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> dial = {"abc", "def",  "ghi", "jkl",
                               "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string curr = "";
        int i = 0;
        solve(digits, i, curr, ans, dial);
        return ans;
    }
};