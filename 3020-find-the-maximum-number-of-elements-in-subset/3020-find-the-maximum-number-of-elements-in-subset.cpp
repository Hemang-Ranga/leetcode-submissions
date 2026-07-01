class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans=1;
        unordered_map<long long, int> m;
        for(int i: nums){
            m[i]++;
        }
        //handle 1 separately
        if(m.find(1) != m.end()){
            if(m[1]%2==0) ans=m[1]-1;
            else ans=m[1];
        }
        //taking each element as first
        for(auto i: m){
            long long curr = i.first;
            if(curr==1) continue;
            int len=0;
            while(m.find(curr)!=m.end() && m[curr]>=2){
                len+=2;
                curr = curr*curr;
            }
            if(m.find(curr)!=m.end() && m[curr]==1) len++;
            else len--;
            ans = max(ans,len);
        }
        return ans;
    }
};