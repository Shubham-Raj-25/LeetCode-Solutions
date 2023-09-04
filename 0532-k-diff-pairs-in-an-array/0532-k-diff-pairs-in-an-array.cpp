class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums) mp[it]++;
        int ans = 0;
        for(auto it:mp){
            if(k){
                if(mp.find(it.first+k)!=mp.end()) ans++;
            }
            else
                ans += mp[it.first] > 1 ? 1:0;
        }
        return ans;
    }
};