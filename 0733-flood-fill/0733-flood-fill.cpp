class Solution {
public:
    void dfs(vector<vector<int>> &img, vector<vector<int>> &ans, int iniclr, int newclr, int sr, int sc){
        int m = img.size(), n = img[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        ans[sr][sc]=newclr;
        for(int i=0; i<4; i++){
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && img[nrow][ncol]== iniclr && ans[nrow][ncol]!=newclr) dfs(img, ans, iniclr, newclr, nrow, ncol);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int inicolor = image[sr][sc];
        dfs(image,ans,inicolor,color,sr,sc);
        return ans;
    }
};