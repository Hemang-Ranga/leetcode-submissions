class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), cnt=0, max_cnt=0;
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                cnt++;
                if(cnt>max_cnt) max_cnt=cnt;
            }
            else cnt=0;
        }
        return max_cnt;
    }
};