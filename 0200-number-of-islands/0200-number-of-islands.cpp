class Solution {
public:
    void dfs(int r, int c, vector<vector<char>> &grid, vector<vector<bool>> &vis){
        int m=grid.size(), n=grid[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        vis[r][c]=true;
        for(int i=0; i<4; i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1'){
                if (!vis[nr][nc]) dfs(nr,nc,grid,vis);
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
                    dfs(i,j,grid,visited);
                }
            }
        }
        return cnt;
    }
};