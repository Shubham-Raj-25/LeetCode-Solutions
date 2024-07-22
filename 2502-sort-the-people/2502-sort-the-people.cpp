class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,string> data;
        vector<string> ans;

        for(int i=0;i<names.size();i++)
            data[heights[i]] = names[i];
        sort(heights.rbegin(),heights.rend());
        
        for(auto it: heights)
            ans.push_back(data[it]);
        
        return ans;
    }
};