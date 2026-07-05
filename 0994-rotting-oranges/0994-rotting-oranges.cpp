class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size(), fresh=0, level=0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [r,c] = q.front();
                q.pop();
                for(int i=0; i<4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                        q.push({nr,nc});
                        grid[nr][nc]=2;
                        fresh--;
                    }
                }
            }
            if(!q.empty()) level++;
        }
        if(fresh==0) return level;
        return -1;
    }
};