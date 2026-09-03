class Solution {
public:
    string invert(string str){
        for(char& c: str){
            c ^= 1;
        }
        return str;
    }

    string fun(int n){
        if(n==1) return "0";
        string str1 = fun(n-1);
        string str2 = invert(str1);
        reverse(str2.begin(), str2.end());
        return str1 + "1" + str2;
    }

    char findKthBit(int n, int k) {
        string s = fun(n);
        return s[k-1];
    }
};