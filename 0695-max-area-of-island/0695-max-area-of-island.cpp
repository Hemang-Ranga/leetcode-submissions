class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>> &vis){
        int m=grid.size(), n=grid[0].size(), area=0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = true;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            area++;
            int r=p.first, c=p.second;
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                    if(!vis[nr][nc]){
                        q.push({nr,nc});
                        vis[nr][nc]=true;
                    }
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), maxarea=0;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int area = bfs(i,j,grid,visited);
                    maxarea = max(maxarea, area);
                }
            }
        }
        return maxarea;
    }
};