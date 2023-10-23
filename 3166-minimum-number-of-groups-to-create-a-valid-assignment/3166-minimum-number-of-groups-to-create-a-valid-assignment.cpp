class Solution {
public:
    bool isPossible(unordered_map<int, int>& mp,int x) {
        for (auto it : mp) {
            int rem = it.second % x;
            int q = it.second / x;
            if (rem < x - 1) {
                int req = (x - 1) - rem;
                if (q >= req) rem = x - 1;
            }
            if (0 < rem && rem < x - 1) return false;
        }
        return true;
    }

    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        
        int mini = 1e9;
        int count;
        for(auto it:mp)
            mini = min(mini,it.second);
        
        mini++;
        
        while(mini>0){
            if (isPossible(mp,mini)) {
                int out = 0;
                for (auto it : mp) {
                    int rem = it.second % mini;
                    out += it.second / mini;
                    if (rem > 0) out++;
                }
                return out;
            }
            mini--;
        }
        
        return -1;
        
    }
};