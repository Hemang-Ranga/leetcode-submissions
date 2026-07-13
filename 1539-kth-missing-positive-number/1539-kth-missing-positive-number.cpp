class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        vector<int> v;
        for (int j = 1; j <= 2000 && i < arr.size(); j++) {
            if (arr[i] == j)
                i++;
            else {
                v.push_back(j);
                if (v.size() == k)
                    break;
            }
        }
        int ele = arr[arr.size() - 1] + 1;
        while (v.size() < k) {
            v.push_back(ele++);
        }
        return v[v.size() - 1];
    }
};