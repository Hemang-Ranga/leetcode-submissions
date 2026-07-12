class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr;
        unordered_map<int, int> m;
        sort(ans.begin(), ans.end());
        int n = arr.size(), i = 0, rank = 1;
        while (i < n) {
            m[ans[i]] = rank;
            while (i < n - 1 && ans[i] == ans[i + 1])
                i++;
            i++;
            rank++;
        }
        for (int i = 0; i < n; i++) {
            ans[i] = m[arr[i]];
        }
        return ans;
    }
};