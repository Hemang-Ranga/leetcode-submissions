class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int k = target, x=maxDoubles, cnt=0;
        while(k!=1 && x>0){
            if(k%2==1){
                k--;
                cnt++;
            }
            else{
                k /= 2;
                x--;
                cnt++;
            }
        }
        cnt += (k-1);
        return cnt;
    }
};