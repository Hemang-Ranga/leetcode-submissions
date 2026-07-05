class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>> &vis){
        int m=grid.size(), n=grid[0].size(), s=0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = true;
        while(!q.empty()){
            pair<int,int> u = q.front();
            q.pop();
            int r = u.first, c = u.second;
            s += grid[r][c];
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]>0 && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=true;
                }
            }
        }
        return s;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), maxfish=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]>0 && !visited[i][j]){
                    int fishes = bfs(i,j,grid,visited);
                    maxfish = max(fishes,maxfish);
                }
            }
        }
        return maxfish;
    }
};