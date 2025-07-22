class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, right = 0;
        int currSum = 0, maxSum = 0;

        while (right < nums.size()) {
            if (seen.find(nums[right]) == seen.end()) {
                currSum += nums[right];
                seen.insert(nums[right]);
                maxSum = max(maxSum, currSum);
                right++;
            } else {
                currSum -= nums[left];
                seen.erase(nums[left]);
                left++;
            }
        }

        return maxSum;
    }
};