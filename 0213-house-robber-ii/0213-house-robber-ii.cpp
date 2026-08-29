class Solution {
public:
    int f(int start, int i, vector<int>& nums) {
        int prevPrev = 0;
        int prev = nums[start];
        for (int j = start + 1; j <= i; j++) {
            int a = nums[j] + prevPrev;
            int b = prev;
            int current = max(a, b);
            prevPrev = prev;
            prev = current;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return max(f(0, n - 2, nums), f(1, n - 1, nums));
    }
};