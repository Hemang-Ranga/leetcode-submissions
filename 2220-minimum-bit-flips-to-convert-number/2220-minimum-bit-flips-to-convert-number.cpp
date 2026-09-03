class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n=start, m=goal, cnt=0;
        while(n!=0 || m!=0){
            if((n&1)!=(m&1)) cnt++;
            n=n>>1;
            m=m>>1;
        }
        return cnt;
    }
};