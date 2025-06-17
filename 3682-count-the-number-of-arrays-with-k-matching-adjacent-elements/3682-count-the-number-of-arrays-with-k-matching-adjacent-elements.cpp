class Solution {
private:
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

long long power(long long a, long long b, int mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

long long nCr_mod(int n, int r) {
    static std::vector<long long> fact(MAX, 1), invFact(MAX, 1);
    static bool initialized = false;

    if (!initialized) {
        for (int i = 1; i < MAX; ++i)
            fact[i] = (fact[i - 1] * i) % MOD;

        invFact[MAX - 1] = power(fact[MAX - 1], MOD - 2, MOD);
        for (int i = MAX - 2; i >= 1; --i)
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;

        initialized = true;
    }

    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}
public:
    int countGoodArrays(int n, int m, int k) {
        return nCr_mod(n-1,n-k-1)%MOD * power(m-1,n-k-1,MOD)%MOD * m % MOD; 
    }
};

/*

n,m and k

k i'ss should be there such that:
    arr[i-1] == arr[i]

n=3,m=2,k=1

_ _ _ 

1 1 1
1 1 2
1 2 2
2 2 2

n=4,m=2,k=2

_ _ _ _

1 1 1 2
2 1 1 1
1 2 2 2
1 1 2 2
2 2 1 1
2 2 2 1 

n = 5, m = 2, k = 0

_ _ _ _ _ 

1 2 1 2 1
2 1 2 1 2


brute force might not work
f(i,prev,k) : TLE


_ _ _ _ 
m m m m-1


k to fill

_ _ _   _  _
m m m  m-1 m-1
    |
    if k exaushted

n = 3, m = 2, k = 1

_ _ _ 
2*2*1 = 4

n = 4, m = 2, k = 2

_ _ _ _

(2)(2) : 4
1(2)  : 2

k (k-1) continuous

* * * * * 

*/ 