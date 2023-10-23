class Solution {
public:
    bool isPowerOfFour(int n) {
        long long prod = 1;
        
        while(prod<n)
            prod *= 4;
        
        return prod == n;
    }
};