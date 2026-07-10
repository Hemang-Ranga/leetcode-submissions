class Solution {
public:
    bool dfs_bipartite(int u, int c, vector<int>& color,
                       vector<vector<int>>& graph) {
        color[u] = c;
        for (int i : graph[u]) {
            if (color[i] == -1) {
                if (!dfs_bipartite(i, 1 - color[u], color, graph))
                    return false;
            } else if (color[i] == color[u])
                return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1) {
                if (!dfs_bipartite(i, 0, color, graph))
                    return false;
            }
        }
        return true;
    }
};