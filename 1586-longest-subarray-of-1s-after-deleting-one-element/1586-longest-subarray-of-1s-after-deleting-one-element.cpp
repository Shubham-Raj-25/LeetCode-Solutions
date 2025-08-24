class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int currSum = 0, prevSum = 0, best = INT_MIN;
        bool zeroFound = false;
        for(int i=0;i<nums.size();i++){
            if(nums[i])
                currSum++;
            else{
                best = max(currSum+prevSum,best);
                prevSum = currSum;
                currSum = 0;
                zeroFound = true;
            }
        }
        if(zeroFound) return max(best,currSum+prevSum);
        return max(best,currSum+prevSum)-1;
    }
};