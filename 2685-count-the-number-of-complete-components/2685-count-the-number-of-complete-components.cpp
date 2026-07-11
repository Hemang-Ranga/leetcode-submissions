class Solution {
public:
    pair<int, int> dfs(int u, vector<bool>& vis, vector<vector<int>>& adj) {
        int double_edges = adj[u].size(), vertices = 0;
        vis[u] = true;
        vertices++;
        for (int i : adj[u]) {
            if (!vis[i]) {
                auto [e, v] = dfs(i, vis, adj);
                double_edges += e;
                vertices += v;
            }
        }
        return {double_edges, vertices};
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<vector<int>> adjlist(n);
        vector<bool> vis(n, false);
        for (auto itr : edges) {
            adjlist[itr[0]].push_back(itr[1]);
            adjlist[itr[1]].push_back(itr[0]);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                auto [double_edges, vertices] = dfs(i, vis, adjlist);
                if (double_edges == vertices * (vertices - 1))
                    cnt++;
            }
        }
        return cnt;
    }
};