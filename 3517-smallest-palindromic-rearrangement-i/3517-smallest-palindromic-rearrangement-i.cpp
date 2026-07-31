class Solution {
public:
    string smallestPalindrome(string s) {
        string first, second;
        vector<int> freq(26);
        for (int i = 0; i < s.size() / 2; i++) {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            while (freq[i] != 0) {
                freq[i]--;
                first.push_back('a' + i);
            }
        }
        second = first;
        reverse(second.begin(), second.end());
        if (s.size() % 2 == 0)
            return first + second;
        else {
            char mid = s[s.size() / 2];
            first.push_back(mid);
            return first + second;
        }
    }
};