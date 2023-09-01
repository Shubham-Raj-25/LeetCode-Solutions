// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

// first time saw a sampling question, lee's soluion below
// ba

class Solution {
public:
    int rand10() {
        int ans = 53;

        while(ans >= 40)
            ans = (rand7()-1)*7 + (rand7()-1); // [ 0 - 48]
    
    return ans % 10 + 1;
    
    }
};