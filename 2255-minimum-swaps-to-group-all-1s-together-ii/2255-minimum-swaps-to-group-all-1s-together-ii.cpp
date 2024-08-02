class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int len = nums.size();
        int totalOnes = 0;
        for(int num : nums) {
            totalOnes += num == 1;
        }

        if (totalOnes == 0) return 0;

        int maxOnes = 0;
        for (int i = 0; i < totalOnes; i++) {
            maxOnes += nums[i];
        }
        
        int currentOnes = maxOnes;
        for (int i = 1; i < len; i++) {
            currentOnes = currentOnes - nums[i - 1] + nums[(i + totalOnes - 1) % len];
            maxOnes = max(maxOnes, currentOnes);
        }
        
        return totalOnes - maxOnes;
    }
};
