class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows==1) return ans;
        ans.push_back({1,1});
        if(numRows==2) return ans;
        for(int i=1; i<numRows-1; i++){
            ans.push_back({1});
            for(int j=0; j<ans[i].size()-1; j++){
                int sum = ans[i][j]+ans[i][j+1];
                ans[i+1].push_back(sum);
            }
            ans[i+1].push_back(1);
        }
        return ans;
    }
};