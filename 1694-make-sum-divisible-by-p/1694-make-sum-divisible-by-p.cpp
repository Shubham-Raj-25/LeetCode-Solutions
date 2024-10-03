class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int rem = accumulate(nums.begin(), nums.end(), 0ll) % p;
        int best = 1e9;
        unordered_map<int, int> dp;
        dp[0] = -1;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            cur %= p;
            dp[cur] = i;
            if (dp.count((cur + p - rem) % p)) {
                best = min(best, i - dp[(cur + p - rem) % p]);
            }
        }
        return best == 1e9 || best == n ? -1 : best;
    }
};