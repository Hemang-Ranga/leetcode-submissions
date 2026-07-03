class Solution {
private:
    void bfs(const vector<vector<int>>&adj, int u, vector<bool> &vis){
        queue<int> q;
        q.push(u);
        vis[u]=true;
        while(!q.empty()){
            u = q.front();
            q.pop();
            for(int i=0; i<adj.size(); i++){
                if(adj[u][i]==1 && !vis[i]){
                    q.push(i);
                    vis[i]=true;
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size(), cnt=0;
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                cnt++;
                bfs(isConnected, i, vis);
            }
        }
        return cnt;
    }
};