class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), cnt=0, candidate=0;
        for(int i=0; i<n; i++){
            if(cnt==0){
                candidate = nums[i];
                cnt++;
                continue;
            }
            if(nums[i]==candidate) cnt++;
            else cnt--;
        }
        return candidate;
    }
};