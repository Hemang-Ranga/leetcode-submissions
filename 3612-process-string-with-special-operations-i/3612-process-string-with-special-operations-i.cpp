class Solution {
public:
    string processStr(string s) {
        string result ="";
        for(auto i: s){
            if(i>='a' && i<='z') result+=i;
            else if(i=='#') result+=result;
            else if(i=='%') reverse(result.begin(), result.end());
            else{
                if(!result.empty()) result.pop_back();
            }
        }
        return result;
    }
};