class Solution {
public:
    int check(vector<int>& arr, int largestsum) {
        int sum = arr[0], splits = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (sum + arr[i] > largestsum) {
                sum = arr[i];
                splits++;
            } else
                sum += arr[i];
        }
        return splits;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()),
            high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(nums, mid) > k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};