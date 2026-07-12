class Solution {
public:
    int check(vector<int>& a, int d) {
        int sum = 0;
        for (int i = 0; i < a.size(); i++) {
            sum += (a[i] + d - 1) / d;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(), high = *max_element(nums.begin(), nums.end()),
            low = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(nums, mid) <= threshold)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};