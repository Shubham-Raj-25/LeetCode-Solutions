class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, r = 0;
        while(numBottles){
            ans += numBottles;
            int temp = numBottles+r;
            numBottles = (numBottles+r)/numExchange;
            r = temp%numExchange;
        }
        return ans;
    }
};