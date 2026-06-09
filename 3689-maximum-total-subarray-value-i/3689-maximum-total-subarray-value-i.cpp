class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long max, min;
        auto ans = minmax_element(nums.begin(), nums.end());
        min = *ans.first;
        max = *ans.second;
        return (max-min)*k;
    }
};