class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        int l=0, r=n-1, index=-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                index = mid;
                break;
            }
            else if(nums[mid]<target) l=mid+1;
            else r=mid-1;
        }
        int i=index, j=index;
        if(index==-1){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else{
            while(i>0 && nums[i-1]==target) i--;
            while(j<n-1 && nums[j+1]==target) j++;
            ans.push_back(i);
            ans.push_back(j);
        }
        return ans;
    }
};