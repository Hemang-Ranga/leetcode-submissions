class Solution {
public:
    bool is_valid(vector<vector<char>>& board, int sr, int sc, int er, int ec) {
        unordered_set<int> s;
        for (int i = sr; i <= er; i++) {
            for (int j = sc; j <= ec; j++) {
                if (board[i][j] == '.')
                    continue;
                if (s.find(board[i][j]) != s.end())
                    return false;
                s.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        // validate row
        for (int i = 0; i < n; i++) {
            unordered_set<int> s;
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.')
                    continue;
                if (s.find(board[i][j]) != s.end())
                    return false;
                s.insert(board[i][j]);
            }
        }

        // validate col
        for (int j = 0; j < n; j++) {
            unordered_set<int> s;
            for (int i = 0; i < n; i++) {
                if (board[i][j] == '.')
                    continue;
                if (s.find(board[i][j]) != s.end())
                    return false;
                s.insert(board[i][j]);
            }
        }

        // validate 3*3 boxes
        for (int sr = 0; sr < 9; sr += 3) {
            int er = sr + 2;
            for (int sc = 0; sc < 9; sc += 3) {
                int ec = sc + 2;
                if (!is_valid(board, sr, sc, er, ec))
                    return false;
            }
        }

        return true;
    }
};