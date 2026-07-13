class Solution {
private:
    int sum(vector<int>& a) {
        int s = 0;
        for (int i : a) {
            s += i;
        }
        return s;
    }
    int max(vector<int>& a) {
        int m = -1;
        for (int i : a) {
            if (i > m)
                m = i;
        }
        return m;
    }
    int check(vector<int>& a, int capacity) {
        int days = 0, s = 0;
        for (int i = 0; i < a.size(); i++) {
            s += a[i];
            if (s > capacity) {
                days++;
                s = a[i];
            }
        }
        days++;
        return days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(), high = sum(weights), low = max(weights);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(weights, mid) <= days)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};