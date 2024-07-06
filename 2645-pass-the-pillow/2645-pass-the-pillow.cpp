class Solution {
public:
    int passThePillow(int n, int t) {
        n--;
        int k = t%(2*n);
        if(k<=n)
            return k+1;
        return 2*n-k+1;
    }
};