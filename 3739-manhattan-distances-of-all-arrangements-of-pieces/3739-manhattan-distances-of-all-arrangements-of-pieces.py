class Solution:
    def distanceSum(self, m: int, n: int, k: int) -> int:
        base = comb(m*n-2,k-2)
        MOD = 10**9+7
        res = 0
        for dist in range(m):
            res = (res % MOD + dist * (m-dist) * n * n % MOD) % MOD
        for dist in range(n):
            res = (res % MOD + dist * (n-dist) * m * m % MOD) % MOD
        return res * base % MOD