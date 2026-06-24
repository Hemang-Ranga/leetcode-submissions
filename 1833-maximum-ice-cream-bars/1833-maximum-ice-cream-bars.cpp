constexpr int M = 1e5;
int freq[M+1];
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size(), cnt=0;
        for(int i : costs){
            freq[i]++;
        }
        int i=0;
        for(int j=0; j<=M; j++){
            while(freq[j]>0){
                costs[i]=j;
                i++;
                freq[j]--;
            }
        }
        for(int i=0; i<n; i++){
            if(coins>=costs[i]){
                coins-=costs[i];
                cnt++;
            }
        }
        return cnt;
    }
};