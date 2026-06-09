class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size(), sum=0, cnt=0;
        sort(cost.begin(), cost.end());
        int i=n-1;
        while(i>=0){
            if(cnt==2){
                cnt=0;
                i--;
                continue;
            }
            sum+=cost[i];
            i--;
            cnt++;
        }
        return sum;
    }
};