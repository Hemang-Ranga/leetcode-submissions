class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid,
            vector<vector<bool>>& vis) {
        int m = grid.size(), n = grid[0].size(), cnt = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        vis[r][c] = true;
        cnt++;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1 &&
                !vis[nr][nc]) {
                cnt += dfs(nr, nc, grid, vis);
            }
        }
        return cnt;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), total_cnt = 0, border_cnt = 0;
        vector<pair<int, int>> border_1;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    total_cnt++;
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1)
                border_1.push_back({i, 0});
        }
        for (int i = 0; i < m; i++) {
            if (grid[i][n - 1] == 1)
                border_1.push_back({i, n - 1});
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1)
                border_1.push_back({0, j});
        }
        for (int j = 0; j < n; j++) {
            if (grid[m - 1][j] == 1)
                border_1.push_back({m - 1, j});
        }

        for (auto it : border_1) {
            if (!vis[it.first][it.second])
                border_cnt += dfs(it.first, it.second, grid, vis);
        }
        return total_cnt - border_cnt;
    }
};