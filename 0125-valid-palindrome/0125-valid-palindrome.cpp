class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(),
                  [](unsigned char c) { return tolower(c); });
        string str;
        for (char i : s) {
            if ((i >= 48 && i <= 57) || (i >= 97 && i <= 122))
                str.push_back(i);
        }
        int n = str.size();
        int p1 = 0, p2 = n - 1;
        while (p1 < p2) {
            if (str[p1] != str[p2])
                return false;
            p1++;
            p2--;
        }
        return true;
    }
};