class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size(), i = 0, first, last;
        vector<int> ans;
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]] = i;
        }
        while (i < n) {
            first = i;
            last = mp[s[i]];
            while (i < last) {
                last = max(last, mp[s[i]]);
                i++;
            }
            ans.push_back(last - first + 1);
            i++;
        }
        return ans;
    }
};