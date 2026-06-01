class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i=0, last=n;
        while(i<last){
            if(nums[i]==0){
                int j=i;
                while(j<n-1){
                    swap(nums[j], nums[j+1]);
                    j++;
                }
                i=0;
                last--;
            }
            else i++;
        }
    }
};