class Solution {
public:
    int nthUglyNumber(int n) {
        int i = 0, j = 0, k = 0;
        // generate the number, we need to multiply 2,3,5 by ugly numbers only (past calculated)
        vector<int> ugly(n);
        ugly[0] = 1;
        for(int l=1;l<n;l++)
        {
            int op1 = 2*ugly[i], op2 = 3*ugly[j], op3 = 5*ugly[k];
            int mini = min(op1,min(op2,op3));
            ugly[l] = mini;
            if(op1 == mini)
                i++;
            if(op2 == mini)
                j++;
            if(op3 == mini)
                k++;
        }
        return ugly[n-1];
    }
};