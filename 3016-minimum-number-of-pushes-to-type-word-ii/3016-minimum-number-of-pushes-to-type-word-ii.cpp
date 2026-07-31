class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);
        for (char i : word) {
            freq[i - 'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());

        int sum = 0, multiplier = 1;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                break;
            if (i < 8)
                multiplier = 1;
            else if (i < 16)
                multiplier = 2;
            else if (i < 24)
                multiplier = 3;
            else
                multiplier = 4;
            sum += freq[i] * multiplier;
        }
        return sum;
    }
};