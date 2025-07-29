class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> lastSeen(32, -1);

        for (int i = n - 1; i >= 0; --i) {
            for (int bit = 0; bit < 32; ++bit) {
                if ((nums[i] >> bit) & 1) {
                    lastSeen[bit] = i;
                }
            }
            int maxIdx = i;
            for (int bit = 0; bit < 32; ++bit) {
                if (lastSeen[bit] != -1) {
                    maxIdx = max(maxIdx, lastSeen[bit]);
                }
            }

            res[i] = maxIdx - i + 1;
        }

        return res;
    }
};