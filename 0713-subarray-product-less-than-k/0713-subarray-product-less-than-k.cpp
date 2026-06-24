class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size(), cnt=0;
        for(int i=0; i<n; i++){
            int p=1;
            for(int j=i; j<n; j++){
                p*=nums[j];
                if(p<k) cnt++;
                else break;
            }
        }
        return cnt;
    }
};