class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<vector<int>> meetings;
        int n = startTime.size();
        
        for (int i = 0; i < n; i++) {
            meetings.push_back({startTime[i], endTime[i]});
        }
        
        sort(meetings.begin(), meetings.end()); 
        
        vector<int> leftSpace, rightSpace, leftMax, rightMax;
        int l = 0;
        int leftmax = 0;
        for (int i = 0; i < n; i++) {
            leftSpace.push_back(meetings[i][0] - l);
            l = meetings[i][1];
            leftmax = max(leftmax,leftSpace.back());
            leftMax.push_back(leftmax);
        }
        
        int r = eventTime;
        int rightmax = 0;
        for(int i=n-1;i>=0;i--){
            rightSpace.push_back(r - meetings[i][1]);
            r = meetings[i][0];
            rightmax = max(rightmax, rightSpace.back());
            rightMax.push_back(rightmax);
        }
        reverse(rightSpace.begin(),rightSpace.end());
        reverse(rightMax.begin(),rightMax.end());
        
        int ans = 0;
        
        // cout << 
        
        for(int i=0;i<n;i++){
            int currDuration = meetings[i][1] - meetings[i][0];
            int toAdd = 0;
            if(i > 0 && leftMax[i-1] >= currDuration){
                toAdd = currDuration;
            }
            if(i < n-1 && rightMax[i+1] >= currDuration){
                toAdd = currDuration;
            }
            ans = max(leftSpace[i] + rightSpace[i] + toAdd, ans);
        }
        
        return ans;
    }
};




/*


// max of left and right free space?

_______------___________----________-----_______



*/ 