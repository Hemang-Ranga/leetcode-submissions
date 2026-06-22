class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0,a=0,l=0,o=0,n=0,min=INT_MAX;
        for(auto i: text){
            if(i=='b') b++;
            else if(i=='a') a++;
            else if(i=='l') l++;
            else if(i=='o') o++;
            else if(i=='n') n++;
        }
        l/=2;
        o/=2;
        if(min>b) min=b;
        if(min>a) min=a;
        if(min>l) min=l;
        if(min>o) min=o;
        if(min>n) min=n;
        return min;
    }
};