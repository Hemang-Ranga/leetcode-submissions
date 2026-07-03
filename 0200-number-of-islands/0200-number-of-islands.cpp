class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>> &vis){
        int m=grid.size(), n=grid[0].size();
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int r=p.first, c=p.second;
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1'){
                    if(!vis[nr][nc]){
                        q.push({nr,nc});
                        vis[nr][nc]=true;
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size(), cnt=0;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    cnt++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return cnt;
    }
};