class Solution {
public:
    int countOrders(int n) {
        long long ans = 1;
        int mod = 1e9+7;
        // 2n slots, at each putting we have (2n)(2n-1)/2 numbers of valid ways
        while(n>0){
            ans = (ans%mod * 2*n * (2*n-1) / 2)%mod;
            n--;
        }

        return ans%mod;
    }
};