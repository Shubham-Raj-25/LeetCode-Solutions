class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> mp;
        long long ans = LLONG_MIN;
        long long sum = 0;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];

            int rem = (i+1) % k;

            if(rem == 0){
                ans = max(ans, sum);
            }

            if(mp.count(rem)){
                ans = max(ans, sum - mp[rem]);
                mp[rem] = min(mp[rem], sum);
            }
            else{
                mp[rem] = sum;
            }
        }

        return ans;
    }
};