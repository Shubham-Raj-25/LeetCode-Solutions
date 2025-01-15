// https://leetcode.com/problems/minimize-xor/solutions/2650706/deep-explanation-and-solution-for-someone-who-isn-t-good-at-bit-problems/?envType=daily-question&envId=2025-01-15
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bitsToHave = __builtin_popcount(num2);
        int ans = 0;

        // make ans as close to num1 making sure to use max bitsToHave bits
        for(int i=31;i>=0 && bitsToHave; i--){
            if(num1 & (1 << i)){ // if it has a set bit at ith pos
                bitsToHave--;
                ans |= (1 << i); // set the bit at ith position
            }
        }

        // if some excess bitsToHave is there, set it from right to left to make it least number
        for(int i=0; i<=31 && bitsToHave; i++){
            if((ans & (1 << i)) == 0){ // unset
                bitsToHave--;
                ans |= (1 << i);
            }
        }

        return ans;
    }
};