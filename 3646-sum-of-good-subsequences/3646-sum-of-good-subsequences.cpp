class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        unordered_map<int,int> result;
        unordered_map<int,long long> count;
        int ans = 0;
        int mod = 1e9+7;

        for(int num : nums){
            count[num+1] = (count[num+1] + count[num] + count[num+2] + 1) % mod;
            long curr = result[num] + result[num+2];
            curr += 1ll * (count[num] + count[num+2] + 1) * num;
            result[num+1] = (result[num+1] + curr) % mod;
        }

        for(auto it : result)
            ans = (ans + it.second) % mod;
        
        return ans;

    }
};