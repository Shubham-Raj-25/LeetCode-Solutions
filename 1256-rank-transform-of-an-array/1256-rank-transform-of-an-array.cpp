class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // sort and mapping?
        unordered_map<int,int> mp;
        vector<int> data = arr;
        vector<int> ans;
        
        sort(data.begin(),data.end());
        
        int curr_rank = 1;

        for(int i=0;i<data.size();i++)
            if(i != 0 && data[i] == data[i-1])
                continue;
            else
                mp[data[i]] = curr_rank++;
        
        for(auto it: arr)
            ans.push_back(mp[it]);

        return ans;
    }
};