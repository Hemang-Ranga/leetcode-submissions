class Solution {
public:
    bool find(vector<vector<char>>& board, int r, int c, string& word,
              int ind) {
        int m = board.size(), n = board[0].size();
        if (ind >= word.size())
            return true;
        if (r >= m || r < 0 || c >= n || c < 0 || board[r][c] == '$' ||
            board[r][c] != word[ind]) {
            return false;
        }
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};
        char temp = board[r][c];
        board[r][c] = '$';
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (find(board, nr, nc, word, ind + 1))
                return true;
        }
        board[r][c] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && find(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};