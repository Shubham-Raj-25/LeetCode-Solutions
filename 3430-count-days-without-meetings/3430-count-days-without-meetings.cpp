class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0;
        sort(meetings.begin(),meetings.end());
        int maxEnd = INT_MIN;
        
        for(int i=0;i<meetings.size();i++){
            maxEnd = max(meetings[i][1],maxEnd);
            int end = meetings[i][1];
            while(i < meetings.size()-1 && end >= meetings[i+1][0]){
                end = max(end, meetings[i+1][1]);
                i++;
                maxEnd = max(meetings[i][1],maxEnd);
            }
            if(i == meetings.size()-1){
                continue;
            }
            ans += meetings[i+1][0] - end - 1;
        }
        ans += meetings[0][0] - 1;
        ans += days - maxEnd;
        return ans;
    }
};

/*

 ----
      -----
--------------

*/ 