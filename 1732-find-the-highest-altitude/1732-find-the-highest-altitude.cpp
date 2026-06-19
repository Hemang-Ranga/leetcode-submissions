class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size(),h=0, h_max=0;
        for(int i=0; i<n; i++){
            h+=gain[i];
            if(h_max<h) h_max=h;
        }
        return h_max;
    }
};