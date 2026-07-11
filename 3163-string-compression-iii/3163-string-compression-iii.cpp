class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        char c = word[0];
        int n = word.size(), cnt_c = 1;
        for (int i = 1; i < n; i++) {
            if (c == word[i] && cnt_c < 9)
                cnt_c++;
            else {
                comp.push_back(cnt_c + '0');
                comp.push_back(c);
                c = word[i];
                cnt_c = 1;
            }
        }
        comp.push_back(cnt_c + '0');
        comp.push_back(c);
        return comp;
    }
};