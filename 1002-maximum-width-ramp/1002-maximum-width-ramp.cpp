class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> decreasingIndices;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (decreasingIndices.empty() || nums[decreasingIndices.top()] > nums[i]) {
                decreasingIndices.push(i);
            }
        }
        
        int maxWidth = 0;
        for (int j = nums.size() - 1; j >= 0; --j) {
            while (!decreasingIndices.empty() && nums[decreasingIndices.top()] <= nums[j]) {
                maxWidth = max(maxWidth, j - decreasingIndices.top());
                decreasingIndices.pop();
            }
        }
        
        return maxWidth;
    }
};
