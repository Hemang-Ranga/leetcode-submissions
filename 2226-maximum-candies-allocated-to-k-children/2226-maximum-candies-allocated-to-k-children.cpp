class Solution {
public:
    long long check(vector<int>& arr, long long maxcandies) {
        long long kids = 0;
        for (int i : arr) {
            kids += i / maxcandies;
        }
        return kids;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.begin(), candies.end(), 0LL),
                  low = 1, high = *max_element(candies.begin(), candies.end());
        if (sum < k)
            return 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(candies, mid) >= k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};