class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int power =  log10(n)/log10(4);
        return pow(4,power) == n;
    }
};