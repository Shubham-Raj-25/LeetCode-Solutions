class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        sort(interval.begin(),interval.end());

        vector<vector<int>> ans;
        ans.push_back(interval[0]);
        for(int i=1;i<interval.size();i++){
            if(ans.back()[0] <= interval[i][0] && ans.back()[1] >= interval[i][0]){
                ans.back()[1] = max(ans.back()[1],interval[i][1]);
            }
            else
                ans.push_back(interval[i]);
        }

        return ans;

    }
};