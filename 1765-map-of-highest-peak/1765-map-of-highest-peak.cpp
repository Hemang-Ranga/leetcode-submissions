class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(), n=isWater[0].size();
        queue<tuple<int,int,int>> q;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        vector<vector<int>> height(m, vector<int>(n,-1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j]==1){
                    q.push({i,j,0});
                    height[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto [r,c,d] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && isWater[nr][nc]==0 && height[nr][nc]==-1){
                    q.push({nr,nc,d+1});
                    height[nr][nc] = d+1;
                }
            }
        }
        return height;
    }
};