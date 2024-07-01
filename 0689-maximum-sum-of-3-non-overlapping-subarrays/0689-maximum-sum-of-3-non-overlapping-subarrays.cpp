class Solution {
public:
    vector<int> ans;

    vector<int> getSubarraySum(vector<int>& arr, int k) {
        int sum = 0;
        vector<int> ret;
        for (int i = 0; i < k; i++)
            sum += arr[i];
        
        ret.push_back(sum);

        for (int r = k, l = 0; r < arr.size(); r++) {
            sum += arr[r];
            sum -= arr[l];
            l++;
            ret.push_back(sum);
        }

        return ret;
    }

    void path_trace(int idx, int k, int element_left, vector<int>& data, vector<vector<int>>& dp) {
        if (element_left <= 0)
            return;
        else {
            int pick = data[idx] + dp_func(idx + k, k, element_left - 1, data, dp);
            int not_pick = dp_func(idx + 1, k, element_left, data, dp);
            if (pick >= not_pick) {
                ans.push_back(idx); // as picking this proved beneficial
                path_trace(idx + k, k, element_left - 1, data, dp);
            } else {
                path_trace(idx + 1, k, element_left, data, dp);
            }
        }
    }

    int dp_func(int idx, int k, int element_left, vector<int>& data, vector<vector<int>>& dp) {
        if (element_left == 0)
            return 0;

        if (idx >= data.size()) {
            if (element_left != 0)
                return INT_MIN;
            return 0;
        } else if (dp[idx][element_left] != -1)
            return dp[idx][element_left];
        else {
            int pick = data[idx] + dp_func(idx + k, k, element_left - 1, data, dp);
            int not_pick = dp_func(idx + 1, k, element_left, data, dp);
            return dp[idx][element_left] = max(pick, not_pick);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // store the sum of all possible subarray and then find by dp        
        vector<int> data = getSubarraySum(nums, k);
        int n = data.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        dp_func(0, k, 3, data, dp);
        path_trace(0, k, 3, data, dp);
        return ans;
    }
};
