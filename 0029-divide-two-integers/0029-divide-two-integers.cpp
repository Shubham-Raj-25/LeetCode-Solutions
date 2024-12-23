class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }
        if (dividend == divisor)
            return 1;
        bool sign = (dividend < 0) == (divisor < 0);
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;
        while (n >= d) {

            long long inc = 1;
            while (n >= d * inc) {
                inc <<= 1;
            }
            inc >>= 1;
            ans += inc;
            n = n - d * inc;
        }

        if (ans > INT_MAX)
            return INT_MAX;

        return sign ? ans : -ans;
    }
};