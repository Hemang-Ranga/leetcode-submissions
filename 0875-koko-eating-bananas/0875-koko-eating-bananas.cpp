class Solution {
public:
    int maxvalue(vector<int>& arr) {
        int m = -1;
        for (int i : arr) {
            if (i > m)
                m = i;
        }
        return m;
    }

    long long check(int k, vector<int>& piles, int h) {
        long long hrs = 0;
        for (int i = 0; i < piles.size(); i++) {
            hrs += (piles[i] + k - 1LL) / k;
        }
        return hrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), high = maxvalue(piles), low = 1;
        if (h == n)
            return high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, piles, h) <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};