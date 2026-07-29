class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {
        int m = rowCosts.size(), n = colCosts.size(), cost = 0, temp;
        if (startPos[0] < homePos[0]) {
            temp = startPos[0];
            while (temp < homePos[0]) {
                temp++;
                cost += rowCosts[temp];
            }
        } else {
            temp = startPos[0];
            while (temp > homePos[0]) {
                temp--;
                cost += rowCosts[temp];
            }
        }
        if (startPos[1] < homePos[1]) {
            temp = startPos[1];
            while (temp < homePos[1]) {
                temp++;
                cost += colCosts[temp];
            }
        } else {
            temp = startPos[1];
            while (temp > homePos[1]) {
                temp--;
                cost += colCosts[temp];
            }
        }
        return cost;
    }
};