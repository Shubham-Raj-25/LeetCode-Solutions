class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end());
        int ans = 1;
        int mini = points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=mini)
                {   mini = min(mini,points[i][1]);
                    continue;}
            ans++;
            mini = points[i][1];
        }

        return ans;
    }
};