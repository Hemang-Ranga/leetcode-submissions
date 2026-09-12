class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size(), cnt=0, s=0;
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            m[i] = s+nums[i];
            s+=nums[i];
        }
        for(int i=0; i<n-1; i++){
            int s1 = m[i];
            int s2 = s-m[i];
            if((s1-s2)%2==0) cnt++;
        }
        return cnt;
    }
};