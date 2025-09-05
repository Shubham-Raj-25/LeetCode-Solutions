class Solution {
public:
    int bitCount(long long num){
        int ans = 0;
        while(num > 0){
            ans += num & 1;
            num = num >> 1;
        }
        return ans;
    }
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=0;i<61;i++){
            long long target = (long long)num1 - (long long)num2 * (long long)i;
            int setBits = bitCount(target);
            if(i >= setBits && i <= target){
                return i;
            }
        }
        return -1;
    }
};

/*
   
    num1 -= (2^i + num2)
    i : (0,60)
    num1 : (1,1e9) 
    num2 : (-1e9,1e9) 

    impossible cases -> brute force because i : [0,60] | bfs
                            -> 60

    impossible cases:
        > num1 = num1 - 2^i  - num2
                   +      +     -/+    
        if num1 - num2 <= 0 -> not possible

        if num1 - num2 = 1 -> 1 step (i = 0)
           num1 - num2 = 2 -> 1 step (i = 1)
           num1 - num2 = 3 -> 
            5, 2
            5 = 5 - 2 - 2^0
            2 = 2 - 2 
*/ 