class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(), cnt=0, left=0;
        unordered_map<char, int> m = {{'a',0}, {'b',0}, {'c',0}};
        for(int right=0; right<n; right++){
            m[s[right]]++;
            while(m['a']>=1 && m['b']>=1 && m['c']>=1){
                cnt+=n-right;
                m[s[left]]--;
                left++;
            }
        }
        return cnt;
    }
};