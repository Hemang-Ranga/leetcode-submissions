class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.size());
        int depth = 0;
        for(int i=0; i<seq.size(); i++){
            if(seq[i]=='('){
                depth++;
                if(depth%2 == 0) ans[i]=1;
            }
            else{
                if(depth%2 == 0) ans[i]=1;
                depth--;
            }
        }
        return ans;
    }
};