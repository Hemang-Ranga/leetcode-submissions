class Solution {
public:
    int check(vector<int>& arr, int day, int k) {
        int cnt = 0, bouqets = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= day)
                cnt++;
            else {
                bouqets += cnt / k;
                cnt = 0;
            }
        }
        bouqets += cnt / k;
        return bouqets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(),
            high = *max_element(bloomDay.begin(), bloomDay.end()),
            low = *min_element(bloomDay.begin(), bloomDay.end());
        if (m * 1LL * k > n)
            return -1;
        else if (m * 1LL * k == n)
            return high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(bloomDay, mid, k) >= m)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};