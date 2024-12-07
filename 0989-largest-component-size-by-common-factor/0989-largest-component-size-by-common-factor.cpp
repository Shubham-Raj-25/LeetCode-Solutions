class Solution {
private:
void unionBySize(int i, int j, vector<int>& par, vector<int>& size) {
    int u = findUPar(i, par);
    int v = findUPar(j, par);

    if (u == v) return;
    else if (size[u] > size[v]) {
        par[v] = par[u];
        size[u] += size[v];
    } else {
        par[u] = par[v];
        size[v] += size[u];
    }
}

int findUPar(int u, vector<int>& par) {
    if (par[u] == u)
        return u;
    return par[u] = findUPar(par[u], par);
}

void SieveOfEratosthenes(int n, vector<bool>& prime) {
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
}

public:
int largestComponentSize(vector<int>& nums) {
    vector<bool> primes(1e5+1, true);
    SieveOfEratosthenes(1e5+1, primes);
    vector<int> size(1e5+1, 1);
    vector<int> par(1e5+1);
    for (int i = 0; i <= 1e5; i++)
        par[i] = i;
    int ans = 0;

    // set<int> primes_st;

    // for (int i = 2; i < 1e5+1; i++)
    //     if (primes[i]) primes_st.insert(i);

    for (int num : nums) {
         for(int f = 2; f <= sqrt(num); f++)
            if(num % f == 0)
                unionBySize(num,f,par,size),
                unionBySize(num,num/f,par,size);
    }

    unordered_map<int, int> mp;
    for (int num : nums) {
        mp[findUPar(num, par)]++;
        ans = max(ans, mp[findUPar(num, par)]);
    }

    return ans;
}
};
