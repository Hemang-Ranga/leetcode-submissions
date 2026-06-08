class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
        for(int i=0; i<n; i++){
            if(nums[i]>=0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        int i=0, j=0, k=0, chance=0;
        while(i<n/2 || j<n/2){
            if(chance==0){
                nums[k]=pos[i];
                i++;
                chance=1;
            }
            else{
                nums[k]=neg[j];
                j++;
                chance=0;
            }
            k++;
        }
        return nums;
    }
};