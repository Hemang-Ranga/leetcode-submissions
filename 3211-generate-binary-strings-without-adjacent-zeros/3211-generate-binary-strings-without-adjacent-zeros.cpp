class Solution {
public:
    vector<string> validStrings(int n) {
        if (n == 1)
            return {"0", "1"};
        vector<string> ans, prev = validStrings(n - 1);
        for (auto i : prev) {
            ans.push_back(i + "1");
            if (i[n - 2] == '1')
                ans.push_back(i + "0");
        }
        return ans;
    }
};