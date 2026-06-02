class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ones=0, max_ones=0;
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                ones++;
                if(ones>max_ones) max_ones=ones;
            }
            else ones=0;
        }
        return max_ones;
    }
};