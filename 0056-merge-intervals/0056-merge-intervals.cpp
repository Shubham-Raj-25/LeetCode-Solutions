class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int start = -1, end = -1;
        for(int i=0; i<intervals.size(); i++){
            if(start == -1){
                start = intervals[i][0];
                end = intervals[i][1];
            }
            if(end < intervals[i][0]){
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            end = max(end, intervals[i][1]);
        }
        ans.push_back({start,end});
        return ans;
    }
};