class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // no of intersection we need to find
        map<int,int> mp;
        int ans = 1;
        for(auto interval : intervals){
            mp[interval[0]]++;
            mp[interval[1]+1]--;
        }
        int intersection = 0;
        for(auto it: mp){
            intersection += it.second;
            ans = max(ans, intersection);
        }

        return ans;
    }
};