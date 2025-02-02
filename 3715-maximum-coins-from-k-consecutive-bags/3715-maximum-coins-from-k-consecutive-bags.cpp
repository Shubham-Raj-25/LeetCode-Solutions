class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        long long result = 0, csum = 0, psum = 0;

        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && coins[j][1] <= coins[i][0] + k - 1) {
                csum += (long long)(coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }
            if (j < n) {
                long long val = (long long)(coins[i][0] + k - 1 - coins[j][0] + 1) * coins[j][2];
                psum = (val>0)?val:0;
                result = max(result, csum + psum);
            }
            csum -= (long long)(coins[i][1] - coins[i][0] + 1) * coins[i][2];
        }

        csum = 0, psum = 0;
        for (int i = 0, j = 0; i < n; i++) {
            csum += (long long)(coins[i][1] - coins[i][0] + 1) * coins[i][2];
            while (j < n && coins[j][1] < coins[i][1] - k + 1) {
                csum -= (long long)(coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }
            if (j < n) {
                long long val = (long long)(coins[i][1] - k - coins[j][0] + 1) * coins[j][2];
                psum = (val>0)?val:0;
                result = max(result, csum - psum);
            }
        }

        return result;
    }
};