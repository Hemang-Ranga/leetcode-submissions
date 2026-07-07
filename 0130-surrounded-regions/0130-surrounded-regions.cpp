class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board){
    int m = board.size(), n = board[0].size();
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};

    board[r][c] = 'a';
    for(int i=0;i<4;i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='O'){
            dfs(nr,nc,board);
        }
    }
}

    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int m = board.size(), n = board[0].size();
        vector<pair<int,int>> border_O;
        for(int i=0; i<m; i++){
            if(board[i][0]=='O') border_O.push_back({i,0});
        }
        for(int i=0; i<m; i++){
            if(board[i][n-1]=='O') border_O.push_back({i,n-1});
        }
        for(int j=0; j<n; j++){
            if(board[0][j]=='O') border_O.push_back({0,j});
        }
        for(int j=0; j<n; j++){
            if(board[m-1][j]=='O') border_O.push_back({m-1,j});
        }

        for(auto it: border_O){
            if(board[it.first][it.second]=='O') dfs(it.first, it.second, board);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='a') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};