class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int prevPrev = nums[0];
        int prev = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int a = nums[i] + prevPrev;
            int b = prev;
            int current = max(a, b);
            prevPrev = prev;
            prev = current;
        }
        return prev;
    }
};