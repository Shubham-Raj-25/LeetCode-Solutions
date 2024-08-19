class Solution {
public:
    int func(int generated, int copied, int n){
        if(n == 0)
            return 0;
        
        // either copy, or paste
        int op1 = 1e6, op2 = 1e6;

        // copying
        if(generated > copied) 
            op1 = 1 + func(generated,generated,n);
        // pasting
        if(n >= copied)
            op2 = 1 + func(generated+copied,copied,n-copied);

        return min(op1,op2);

    }
    int minSteps(int n) {
        if(n == 1)
            return 0;
        return 1+func(1,1,n-1);
    }
};