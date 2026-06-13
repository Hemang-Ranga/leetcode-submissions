class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string ans;
        for(auto str: words){
            int w=0;
            for(auto i: str){
                w += weights[i-'a'];
            }
            w=w%26;
            ans.push_back(char('z'-w));
        }
        return ans;
    }
};