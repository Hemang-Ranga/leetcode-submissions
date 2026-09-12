class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt=0, n1=g.size(), n2=s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i=n1-1, j=n2-1;
        while(i>=0 && j>=0){
            if(s[j]>=g[i]){
                cnt++;
                j--;
            }
            i--;
        }
        return cnt;
    }
};