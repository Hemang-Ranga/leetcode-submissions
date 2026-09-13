class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<vector<int>> vec;
        for(auto i : boxTypes){
            vec.push_back({i[1],i[0]});
        }
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
        int maxunits = 0;
        for(auto i: vec){
            if(truckSize<=0) break;
            if(i[1]<=truckSize){
                maxunits += i[0]*i[1];
                truckSize -= i[1];
            }
            else{
                maxunits += truckSize*i[0];
                truckSize=0;
            }
        }
        return maxunits;
    }
};