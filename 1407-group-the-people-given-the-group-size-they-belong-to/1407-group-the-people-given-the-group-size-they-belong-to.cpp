class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        // O(n) TC solution
        map<int,vector<int>> mp;
        vector<vector<int>> ans;

        for(int i=0;i<g.size();i++){

            if(mp[g[i]].size()==g[i]){
                ans.push_back(mp[g[i]]);
                mp[g[i]].clear();
            }
            
            mp[g[i]].push_back(i);
        }

        for(auto it:mp)
            if(it.second.size()!=0)
                ans.push_back(it.second);
        
        return ans;
    }
};