class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int targetSum = 0;
        for (int num : nums) {
            targetSum += num;
        }
        targetSum -= x;

        if (targetSum < 0) return -1;

        int maxSubarrayLength = -1;
        int currentSum = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            currentSum += nums[right];

            while (currentSum > targetSum && left <= right) {
                currentSum -= nums[left];
                left++;
            }

            if (currentSum == targetSum) {
                maxSubarrayLength = max(maxSubarrayLength, right - left + 1);
            }
        }

        int minOperations = (maxSubarrayLength == -1) ? -1 : n - maxSubarrayLength;
        return minOperations;
    }
};