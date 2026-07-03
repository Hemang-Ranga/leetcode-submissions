class Solution {
private:
    void dfs(vector<vector<int>> &adj, int u, vector<bool> &vis){
        vis[u]=true;
        for(int i: adj[u]){
            if(!vis[i]) dfs(adj, i, vis);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size(), cnt=0;
        vector<vector<int>> adj(V);
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(i!=j && isConnected[i][j]==1) adj[i].push_back(j);
            }
        }
        for(int i=0; i<V; i++){
            if(!vis[i]){
                cnt++;
                dfs(adj, i, vis);
            }
        }
        return cnt;
    }
};