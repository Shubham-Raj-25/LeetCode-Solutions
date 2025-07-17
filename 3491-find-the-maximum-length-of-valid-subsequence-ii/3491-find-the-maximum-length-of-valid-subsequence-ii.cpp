class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k , vector<int>(k , 0));
        int maxi = 1;
        for(int num : nums){
            int currNum = num % k;
            for(int mod = 0 ; mod < k ; mod++){
                  int prevNum = (mod - currNum + k) % k;
                  dp[currNum][mod] = max(dp[currNum][mod] , 1 + dp[prevNum][mod]);
                  maxi = max(maxi , dp[currNum][mod]);
            }
        }
        return maxi;
    }
};

/*

2 <= nums.length <= 10^3 : n^2 
1 <= nums[i] <= 10^7
1 <= k <= 10^3


(sub[0] + sub[1]) % k ==
(sub[1] + sub[2]) % k == 
(sub[x - 2] + sub[x - 1]) % k.

for i in range(0,nums.size()):
    for j in range(0,i):
        r = (nums[i]+nums[j]) % k
        dp[i][r] = max(dp[j][r]+1,dp[i][r])

*/ 