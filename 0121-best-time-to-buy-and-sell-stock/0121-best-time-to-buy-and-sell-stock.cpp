class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),maxprofit=0, min=prices[0];
        for(int i=1; i<n; i++){
            if(prices[i]<min){
                min=prices[i];
                continue;
            }
            int profit = prices[i]-min;
            if(profit>maxprofit) maxprofit=profit;
        }
        return maxprofit;
    }
};