class Solution {
public:
    int integerBreak(int n) {
        // math solution
        // keep maximum 3s
        if(n==2) return 1;
        if(n==3) return 2;

        int prod = 1;

        while(n>4){
            prod *= 3;
            n -= 3;
        }

        prod *= n;

        return prod;
    }
};