class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,1e9);
        prev[0]=0;
        for(int i=n-1; i>=0; i--){
            vector<int> curr(amount+1);
            for(int j=1; j<=amount; j++){
                int skip = prev[j];
                int take = 1e9;
                if(j>=coins[i]) take = 1+curr[j-coins[i]];
                curr[j] = min(skip,take);
            }
            prev = curr;
        }
        return (prev[amount]!=1e9) ? prev[amount] : -1;
    }
};