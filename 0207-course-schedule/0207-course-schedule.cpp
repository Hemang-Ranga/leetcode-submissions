class Solution {
private:
    bool dfs_cycle_checker(int u, vector<vector<int>>& adj, vector<bool>& vis,
                           vector<bool>& RecStack) {
        vis[u] = true;
        RecStack[u] = true;
        for (int& i : adj[u]) {
            if (!vis[i]) {
                if (dfs_cycle_checker(i, adj, vis, RecStack))
                    return true;
            } else if (RecStack[i])
                return true;
        }
        RecStack[u] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> RecStack(numCourses, false);
        for (auto i : prerequisites) {
            adjlist[i[0]].push_back(i[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs_cycle_checker(i, adjlist, visited, RecStack))
                    return false;
            }
        }
        return true;
    }
};