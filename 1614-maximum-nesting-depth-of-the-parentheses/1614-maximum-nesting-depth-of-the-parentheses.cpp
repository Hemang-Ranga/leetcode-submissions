class Solution {
public:
    int maxDepth(string s) {
        int depth=0, m=0;
        for(char i: s){
            if(i=='('){
                depth++;
                if(depth>m) m=depth;
            }
            else if(i==')') depth--;
        }
        return m;
    }
};