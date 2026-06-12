class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), max_cnt=0;
        if(n==0) return 0;
        unordered_set<int> s;
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
        for(int i : s){
            if(s.find(i-1)==s.end()){
                int j=i, cnt=1;
                while(s.find(j+1)!=s.end()){
                    cnt++;
                    j++;
                }
                if(cnt>max_cnt) max_cnt=cnt;
            }
        }
        return max_cnt;
    }
};