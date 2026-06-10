class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans, prev;
        if(n==1){
            ans.push_back("0");
            ans.push_back("1");
            return ans;
        }
        prev = validStrings(n-1);
        for(string str: prev){
            if(str.back()=='0'){
                str.push_back('1');
                ans.push_back(str);
            }
            else{
                str.push_back('0');
                ans.push_back(str);
                str[str.size()-1]='1';
                ans.push_back(str);
            }
        }
        return ans;
    }
};