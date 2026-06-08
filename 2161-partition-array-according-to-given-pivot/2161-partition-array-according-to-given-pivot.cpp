class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), cnt=0;
        vector<int> l, g;
        for(int i=0; i<n; i++){
            if(nums[i]<pivot) l.push_back(nums[i]);
            else if(nums[i]>pivot) g.push_back(nums[i]);
            else cnt++;
        }        
        for(int i=0; i<l.size(); i++){
            nums[i]=l[i];
        }
        for(int i=l.size(); i<l.size()+cnt; i++){
            nums[i] = pivot;
        }
        for(int i=0; i<g.size(); i++){
            nums[i+l.size()+cnt] = g[i];
        }
        return nums;
    }
};