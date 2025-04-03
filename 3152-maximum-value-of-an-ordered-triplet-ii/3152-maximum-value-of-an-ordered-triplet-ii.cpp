class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxProd = 0, maxNum = 0, maxDiff = 0;
        
        for(long long num : nums){
            maxProd = max(maxProd, maxDiff * num);
            maxNum = max(maxNum,num);
            maxDiff = max(maxDiff,maxNum-num);
        }

        return maxProd;
    }
};