class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while(1){
            cout << n << endl;
            if(n==2)
                return ans+1;
            if(n==1)
                return ans;
            if(n%2==0){
                {ans += n/2;
                n = n/2;}
            }
            else
                {ans += (n-1)/2;
                n = (n-1)/2+1;}
        }

        return -1;
    }
};