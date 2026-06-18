class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n=matrix[0].size();
        vector<pair<int,int>> zeroes;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0) zeroes.push_back({i,j});
            }
        }
        for(auto itr : zeroes){
            for(int j=0; j<n; j++){
                matrix[itr.first][j]=0;
            }
            for(int i=0; i<m; i++){
                matrix[i][itr.second]=0;
            }
        }
    }
};