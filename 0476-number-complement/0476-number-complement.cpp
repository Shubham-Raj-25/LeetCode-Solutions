class Solution {
public:
    int findComplement(int n) {
        int m=n;
        int mask = 0;
        
        while(m!=0){
            mask = (mask<<1) | 1;
            m = m>>1;                     
        }
        int ans = (~n) & mask;
        
        return ans;
    }
};