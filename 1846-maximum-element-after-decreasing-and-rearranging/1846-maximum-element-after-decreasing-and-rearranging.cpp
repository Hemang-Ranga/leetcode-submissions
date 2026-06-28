constexpr int N = 1e5;
int freq[N+1];
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        for(int i: arr){
            freq[min(i,n)]++;
        }
        int j=0;
        for(int i=0; i<N+1; i++){
            while(freq[i]>0){
                arr[j]=i;
                j++;
                freq[i]--;
            }
        }
        arr[0]=1;
        for(int i=1; i<n; i++){
            arr[i] = min(arr[i-1]+1, arr[i]);
        }
        return arr[n-1];
    }
};