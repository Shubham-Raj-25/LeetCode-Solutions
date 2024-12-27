class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, maxVal = 0;
        for(int i=0;i<values.size();i++){
            ans = max(ans, maxVal + values[i] - i);
            maxVal = max(maxVal, values[i]+i);
        }

        return ans;
    }
};