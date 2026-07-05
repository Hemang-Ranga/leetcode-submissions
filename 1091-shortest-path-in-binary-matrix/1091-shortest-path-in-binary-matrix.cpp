class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& grid){
        int n = grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        int dr[] = {0,1,1,1,0,-1,-1,-1};
        int dc[] = {1,1,0,-1,-1,-1,0,1};
        queue<tuple<int,int,int>> q;
        q.push({row,col,1});
        vis[row][col] = true;
        while(!q.empty()){
            auto [r, c, dis] = q.front();
            q.pop();
            if(r==n-1 && c==n-1) return dis;
            for(int i=0; i<8; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && !vis[nr][nc]){
                    q.push({nr,nc,dis+1});
                    vis[nr][nc]=true;
                }
            }
        }
        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        if(n==1) return 1;
        return bfs(0,0,grid);
    }
};