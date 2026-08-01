const int M = 1e9 + 7;
class Solution {
public:
    int f(long long n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 20;

        long long temp = f(n / 2);
        long long ans = (temp * temp) % M;
        if (n % 2 == 0)
            return ans;
        else
            return (20 * ans) % M;
    }

    int countGoodNumbers(long long n) {
        if (n == 1)
            return 5;
        int x = f(n / 2);
        if (n % 2 == 0)
            return x;
        else
            return (5LL * x) % M;
    }
};