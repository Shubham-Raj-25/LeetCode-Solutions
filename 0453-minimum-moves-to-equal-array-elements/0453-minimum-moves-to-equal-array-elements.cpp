class Solution {
public:
    int minMoves(vector<int>& nums) {
        // take the reverse appraoch, decrease 1 element by 1 rather than increasing n-1
        // elements by 1

        unordered_map<int,int> mp;
        int ans = 0;
        int mini = INT_MAX;

        for(auto it: nums){
            mp[it]++;
            mini = min(mini,it);
        }

        for(auto it: mp)
            ans += (it.first-mini)*it.second;
        
        return ans;

    }
};