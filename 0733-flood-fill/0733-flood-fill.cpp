class Solution {
public:
    void bfs(int sr, int sc, vector<vector<int>> &img, vector<vector<int>> &ans, int newclr, int iniclr){
        int m = img.size(), n = img[0].size();
        queue<pair<int,int>> q;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        q.push({sr,sc});
        ans[sr][sc]=newclr;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int orow = p.first, ocol=p.second;
            for(int i=0; i<4; i++){
                int nrow = orow+delrow[i];
                int ncol = ocol+delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && img[nrow][ncol]==iniclr && ans[nrow][ncol]!=newclr){
                    q.push({nrow, ncol});
                    ans[nrow][ncol] = newclr;
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int inicolor = image[sr][sc];
        bfs(sr,sc,image,ans,color,inicolor);
        return ans;
    }
};