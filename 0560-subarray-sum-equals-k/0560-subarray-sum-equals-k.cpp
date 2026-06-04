class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(), sum=0, cnt=0;
        map<int,int> m;
        m.insert({0,1});
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(m.find(sum-k)!=m.end()) cnt += m[sum-k];
            m[sum]++;
        }
        return cnt;
    }
};