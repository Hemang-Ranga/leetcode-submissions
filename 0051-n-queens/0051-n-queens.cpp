class Solution {
public:
    unordered_set<int> col;
    unordered_set<int> diag;
    unordered_set<int> antiDiag;
    void solve(vector<string>& board, int r, vector<vector<string>>& ans) {
        int n = board.size();
        if (r == n) {
            ans.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (col.find(c) != col.end() || diag.find(r + c) != diag.end() ||
                antiDiag.find(r - c) != antiDiag.end())
                continue;

            board[r][c] = 'Q';
            col.insert(c);
            diag.insert(r + c);
            antiDiag.insert(r - c);

            solve(board, r + 1, ans);

            board[r][c] = '.';
            col.erase(c);
            diag.erase(r + c);
            antiDiag.erase(r - c);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(board, 0, ans);
        return ans;
    }
};