class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int max_count = 0;
        for (int i=0; i < 24; i++) {
            int cur_count = 0;
            for (int num:candidates) {
                if ((num & (1 << i)) != 0) {
                    cur_count++;
                }
            }
            max_count = max(max_count, cur_count);
        }
        return max_count;
    }
};