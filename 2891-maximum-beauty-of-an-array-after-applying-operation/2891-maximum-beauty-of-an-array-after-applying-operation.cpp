class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // line sweep will work
        map<int,int> mp;
        int ans = 0, curr = 0;

        for(int num : nums){
            mp[num-k]++;
            mp[num+k+1]--;
        }

        for(auto it: mp){
            curr += it.second;
            ans = max(ans,curr);
        }

        return ans;
    }
};