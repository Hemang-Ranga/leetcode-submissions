class Solution {
private: 
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<bool>> &vis){
        int m=board.size(), n=board[0].size();
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        vis[r][c]=true;
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='X' && !vis[nr][nc]){
                dfs(nr,nc,board,vis);
            }
        }
    }

public:
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size(), cnt=0;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='X' && !visited[i][j]){
                    cnt++;
                    dfs(i,j,board,visited);
                }
            }
        }
        return cnt;
    }
};