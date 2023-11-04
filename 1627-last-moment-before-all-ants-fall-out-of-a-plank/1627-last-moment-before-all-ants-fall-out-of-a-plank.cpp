class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int leftMax = INT_MIN;
        int rightMin = INT_MAX;
        
        for (int i = 0; i < left.size(); i++) {
            leftMax = max(leftMax, left[i]);
        }
        
        for (int i = 0; i < right.size(); i++) {
            rightMin = min(rightMin, right[i]);
        }
        
        return max(leftMax, n - rightMin);
    }
};