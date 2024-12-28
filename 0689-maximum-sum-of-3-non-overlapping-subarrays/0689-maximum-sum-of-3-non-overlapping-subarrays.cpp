class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), maxSum = 0;
        vector<int> prefixSum(n, 0), leftMaxPos(n, 0), rightMaxPos(n, n - k), ans;

        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        int maxSoFar = prefixSum[k - 1]; 
        for (int i = k; i < n; i++) {
            int currWinSum = prefixSum[i] - prefixSum[i - k];
            if (currWinSum > maxSoFar) {
                leftMaxPos[i] = i - k + 1;
                maxSoFar = currWinSum;
            } else {
                leftMaxPos[i] = leftMaxPos[i - 1];
            }
        }

        maxSoFar = prefixSum[n - 1] - prefixSum[n - 1 - k]; 
        for (int i = n - k - 1; i >= 0; i--) {
            int currWinSum = prefixSum[i + k - 1] - (i > 0 ? prefixSum[i - 1] : 0);
            if (currWinSum >= maxSoFar) {
                rightMaxPos[i] = i;
                maxSoFar = currWinSum;
            } else {
                rightMaxPos[i] = rightMaxPos[i + 1];
            }
        }

        for (int i = k; i <= n - 2 * k; i++) {
            int l = leftMaxPos[i - 1];
            int r = rightMaxPos[i + k];
            int total = (prefixSum[i + k - 1] - prefixSum[i - 1]) + 
                        (prefixSum[l + k - 1] - (l > 0 ? prefixSum[l - 1] : 0)) + 
                        (prefixSum[r + k - 1] - (r > 0 ? prefixSum[r - 1] : 0));
            if (total > maxSum) {
                maxSum = total;
                ans = {l, i, r};
            }
        }

        return ans;
    }
};
