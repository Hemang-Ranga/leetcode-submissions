class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int p1 = 0, p2 = n - 1;
        while (p1 < p2) {
            swap(s[p1], s[p2]);
            p1++;
            p2--;
        }
    }
};