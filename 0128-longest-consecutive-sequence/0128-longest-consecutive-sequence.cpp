class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int ans=1;
        unordered_set<int> s;
        for(int i: nums){
            s.insert(i);
        }
        for(int i: s){
            if(s.find(i-1)==s.end()){
                int curr = i;
                int len=1;
                while(s.find(curr+1)!=s.end()){
                    len++;
                    curr++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};