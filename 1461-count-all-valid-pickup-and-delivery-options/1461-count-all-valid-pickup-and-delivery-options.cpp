class Solution {
public:
    
    int mod = 1e9+7;

    long long factorial(int n){
        if(n==1)
            return 1;
        
        return (n%mod) * (factorial(n-1)%mod);
    }

    int oddProd(int n){
        long long ans = 1, odd = 1;
        for(int i=1;i<=n;i++){
            ans = (ans%mod)*(odd%mod);
            odd += 2;
        }
        return ans%mod;
    }

    int countOrders(int n) {
        return ((long long)oddProd(n)%mod)*((long long)factorial(n)%mod)%mod;
    }
};