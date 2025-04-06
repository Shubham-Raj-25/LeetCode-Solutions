class Solution {
public:
    unordered_map<int, vector<int>> dp;

    vector<int> func(int idx, vector<int>& nums) {
        if (idx == nums.size())
            return vector<int>();

        if (dp.find(idx) != dp.end())
            return dp[idx];

        vector<int> ans = {nums[idx]};

        for (int j = idx + 1; j < nums.size(); j++) {
            if (nums[j] % nums[idx] == 0) {
                vector<int> temp = {nums[idx]};
                vector<int> recursiveResult = func(j, nums);
                temp.insert(temp.end(), recursiveResult.begin(), recursiveResult.end());

                if (temp.size() > ans.size())
                    ans = temp;
            }
        }
        return dp[idx] = ans;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans, temp;
        for (int i = 0; i < nums.size(); i++) {
            temp = func(i, nums);
            if (temp.size() > ans.size())
                ans = temp;
        }
        return ans;
    }
};
