class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int tsum=0, lsum=0, rsum=0, cnt=0;
        for(int i: nums){
            tsum+=i;
        }
        for(int i=0; i<nums.size()-1; i++){
            lsum += nums[i];
            rsum = tsum-lsum;
            if(abs(lsum-rsum)%2==0) cnt++;
        }
        return cnt;
    }
};