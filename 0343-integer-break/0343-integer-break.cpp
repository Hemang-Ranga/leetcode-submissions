class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int mul=1;
        while(n!=4 && n!=2 && n){
            n-=3;
            mul*=3;
        }
        if(n==2) return mul*2;
        else if(n==4) return mul*4;
        return mul;
    }
};