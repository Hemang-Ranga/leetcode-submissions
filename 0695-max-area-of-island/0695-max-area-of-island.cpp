class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>> &vis){
        int m=grid.size(), n=grid[0].size(), curr_area=0, remaining_area=0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        vis[row][col]=true;
        curr_area++;
        for(int i=0; i<4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1){
                if(!vis[nr][nc]){
                    remaining_area += dfs(nr,nc,grid,vis);
                }
            }
        }
        return curr_area+remaining_area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), maxarea=0;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int area = dfs(i,j,grid,visited);
                    maxarea = max(area, maxarea);
                }
            }
        }
        return maxarea;
    }
};