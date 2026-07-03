class Solution {
public:
    void dfs(const vector<vector<int>> &adj, int u, vector<bool> &vis){
        int V=adj.size();
        vis[u]=true;
        for(int i=0; i<V; i++){
            if(adj[u][i]==1 && !vis[i]) dfs(adj, i, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size(), cnt=0;
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                cnt++;
                dfs(isConnected, i, vis);
            }
        }
        return cnt;
    }
};