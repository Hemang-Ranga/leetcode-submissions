class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (int i : bills) {
            if (i == 5)
                five++;
            else if (i == 10 && five >= 1) {
                five--;
                ten++;
            } else if (i == 20 && five >= 1 && ten >= 1) {
                twenty++;
                five--;
                ten--;
            } else if (i == 20 && five >= 3) {
                twenty++;
                five -= 3;
            } else {
                return false;
            }
        }
        return true;
    }
};