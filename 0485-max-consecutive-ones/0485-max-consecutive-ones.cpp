class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0, cnt_i=0, cnt_max=0, n = nums.size();
        while(i<n){
            if(nums[i]==1){
                cnt_i++;
                i++;
            }
            else{
                if(cnt_i>cnt_max) cnt_max = cnt_i;
                cnt_i = 0;
                i++;
            }
        }
        if(cnt_i>cnt_max) cnt_max = cnt_i;
        return cnt_max;
    }
};