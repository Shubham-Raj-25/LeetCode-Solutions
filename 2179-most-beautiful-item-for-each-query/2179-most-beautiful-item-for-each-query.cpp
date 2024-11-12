class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // i = [[1,2],[3,2],[2,4],[5,6],[3,5]]
        // q = [1,2,3,4,5,6]
        map<int,int> mp;
        vector<int> ans;
        for(auto item : items)
            mp[item[0]] = max(mp[item[0]],item[1]);
        
        int maxi = 0;

        for(auto it: mp){
            maxi = max(maxi,it.second);
            mp[it.first] = maxi;
        }

        // for(auto it: mp)
        //     cout << it.first << "  --  " << it.second << endl;

        for(auto q : queries){
            if(mp.find(q) != mp.end())
                ans.push_back(mp[q]);
            else{
                auto it = mp.upper_bound(q);
                if(it != mp.begin()){
                    it--;
                    ans.push_back(it->second);
                }
                else
                    ans.push_back(0);
            }
        }

        return ans;
    }
};