class Solution {
public:
    int integerBreak(int n) {
        // we need to break it into 3s mainly and at last 4
        if(n==2 || n==3) return n-1;

        int ans = 1;

        while(n>4){
            n -= 3;
            ans *= 3;
        }

        ans*=n;

        return ans;
    }
};