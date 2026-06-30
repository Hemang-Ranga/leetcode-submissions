class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums;
        int candidate1=INT_MAX, candidate2=INT_MIN, cnt1=0, cnt2=0;
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(cnt1==0 && nums[i]!=candidate2){
                candidate1=nums[i];
                cnt1++;
            }
            else if(cnt2==0 && nums[i]!=candidate1){
                candidate2=nums[i];
                cnt2++;
            }
            else if(nums[i]==candidate1) cnt1++;
            else if(nums[i]==candidate2) cnt2++;
            else{
                cnt1--; 
                cnt2--;
            }
        }
        cnt1=0, cnt2=0;
        for(int i=0; i<n; i++){
            if(nums[i]==candidate1) cnt1++;
            else if(nums[i]==candidate2) cnt2++;
        }
        if(cnt1>n/3) ans.push_back(candidate1);
        if(cnt2>n/3) ans.push_back(candidate2);
        return ans;
    }
};