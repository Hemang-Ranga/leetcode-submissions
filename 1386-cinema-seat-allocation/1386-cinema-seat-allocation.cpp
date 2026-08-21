class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;
        for (auto& seat : reservedSeats) {
            int r = seat[0];
            int c = seat[1];
            rowMask[r] |= (1 << (c - 1));
        }

        int result = 0;
        for (auto& [row, mask] : rowMask) {
            bool left = !(mask & ((1 << 1) | (1 << 2) | (1 << 3) |
                                  (1 << 4))); // seats 2-5
            bool right = !(mask & ((1 << 5) | (1 << 6) | (1 << 7) |
                                   (1 << 8))); // seats 6-9
            bool middle = !(mask & ((1 << 3) | (1 << 4) | (1 << 5) |
                                    (1 << 6))); // seats 4-7

            if (left && right)
                result += 2;
            else if (left || right || middle)
                result += 1;
        }

        // rows without reservations → always 2 families
        result += (n - rowMask.size()) * 2;

        return result;
    }
};
