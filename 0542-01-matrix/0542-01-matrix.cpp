class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> dist(m,vector<int>(n,-1));
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        queue<tuple<int,int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    dist[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto [r,c,d] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && mat[nr][nc]==1 && dist[nr][nc]==-1){
                    q.push({nr,nc,d+1});
                    dist[nr][nc] = d+1;
                }
            }
        }
        return dist;
    }
};