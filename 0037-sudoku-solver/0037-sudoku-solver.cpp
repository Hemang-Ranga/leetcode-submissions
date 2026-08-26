class Solution {
public:
    bool is_valid(vector<vector<char>>& board, int r, int c, char val) {
        for (int i = 0; i < 9; i++) {
            if (board[i][c] == val)
                return false;
        }
        for (int j = 0; j < 9; j++) {
            if (board[r][j] == val)
                return false;
        }

        int start_i = r / 3 * 3;
        int start_j = c / 3 * 3;
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                if (board[k + start_i][l + start_j] == val)
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char val = '1'; val <= '9'; val++) {
                        if (is_valid(board, i, j, val)) {
                            board[i][j] = val;
                            if (solve(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};