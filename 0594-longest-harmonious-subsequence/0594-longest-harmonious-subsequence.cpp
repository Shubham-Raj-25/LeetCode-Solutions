class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        
        for(auto it:nums)
            mp[it]++;

        int ans = 0;

        for(auto it:nums)
            {   
                if(mp.find(it+1)!=mp.end())
                    ans = max(ans,mp[it]+mp[it+1]);
            }
        
        return ans;

    }
};