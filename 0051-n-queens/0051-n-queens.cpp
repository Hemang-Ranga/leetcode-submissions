class Solution {
public:
    bool isvalid(vector<string>& board, int r, int c) {
        r--;
        int i = r, n = board.size();
        while (i >= 0) {
            if (board[i--][c] == 'Q')
                return false;
        }
        i = r;
        int j = c - 1;
        while (i >= 0 && j >= 0) {
            if (board[i--][j--] == 'Q')
                return false;
        }
        i = r, j = c + 1;
        while (i >= 0 && j <= n) {
            if (board[i--][j++] == 'Q')
                return false;
        }
        return true;
    }

    void solve(vector<string>& board, int r, vector<vector<string>>& ans) {
        int n = board.size();
        if (r == n) {
            ans.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (isvalid(board, r, c)) {
                board[r][c] = 'Q';
                solve(board, r + 1, ans);
                board[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s = "";
        for (int i = 0; i < n; i++) {
            s += ".";
        }
        vector<string> board(n, s);
        solve(board, 0, ans);
        return ans;
    }
};