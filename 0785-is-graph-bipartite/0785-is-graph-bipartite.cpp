class Solution {
public:
    bool bfs_bipartite(int u, int c, vector<int>& color,
                       vector<vector<int>>& graph) {
        queue<int> q;
        q.push(u);
        color[u] = c;
        while (!q.empty()) {
            u = q.front();
            q.pop();
            for (int i : graph[u]) {
                if (color[i] == -1) {
                    q.push(i);
                    color[i] = abs(color[u] - 1);
                } else if (color[i] == color[u])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1) {
                if (!bfs_bipartite(i, 0, color, graph))
                    return false;
            }
        }
        return true;
    }
};