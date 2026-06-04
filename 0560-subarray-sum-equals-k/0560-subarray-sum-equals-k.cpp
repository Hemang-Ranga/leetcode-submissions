class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum=0, cnt=0;
        map<int, int> m;
        m.insert({0,1});
        for(int i=0; i<n; i++){
            sum += nums[i];
            // if(m.find(sum-k)!=m.end()) cnt++;
            // if(m.find(sum)==m.end()) m.insert({sum,i});
            int complement = sum - k;
            if(m.count(complement)) cnt += m[complement];
            m[sum]++;
        }
        return cnt;
    }
};