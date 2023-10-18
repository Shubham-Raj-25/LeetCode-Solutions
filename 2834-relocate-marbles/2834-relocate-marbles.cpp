class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int,int> mp;
        for(auto it: nums)
            mp[it]++;
        
        for(int i=0;i<moveFrom.size();i++){
            if(mp.find(moveFrom[i])==mp.end() || mp[moveFrom[i]] == 0 || moveFrom[i] == moveTo[i])
                continue;
            
            mp[moveTo[i]] += mp[moveFrom[i]];
            mp[moveFrom[i]] = 0;
        }

        vector<int> ans;

        for(auto it:mp)
            if(it.second !=0)
                ans.push_back(it.first);

        sort(ans.begin(),ans.end());

        return ans;
    }
};