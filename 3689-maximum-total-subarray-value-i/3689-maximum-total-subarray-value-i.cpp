class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long max, min;
        auto max_it = max_element(nums.begin(), nums.end());
        auto min_it = min_element(nums.begin(), nums.end());
        max = *(max_it);
        min = *(min_it);
        return (max-min)*k;
    }
};