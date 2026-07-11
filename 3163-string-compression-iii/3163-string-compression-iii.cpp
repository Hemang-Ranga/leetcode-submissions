class Solution {
public:
    string compressedString(string word) {
        string comp;
        char c = word[0];
        int n = word.size(), i = 1, cnt_c = 1;
        if (n == 1) {
            comp.push_back(cnt_c + '0');
            comp.push_back(c);
        }
        while (i < n) {
            while (i < n && c == word[i] && cnt_c < 9) {
                cnt_c++;
                i++;
            }
            comp.push_back(cnt_c + '0');
            comp.push_back(c);
            if (i < n - 1) {
                c = word[i];
                cnt_c = 1;
                i++;
            } else if (i == n - 1) {
                c = word[i];
                cnt_c = 1;
                i++;
                comp.push_back(cnt_c + '0');
                comp.push_back(c);
            }
        }
        return comp;
    }
};