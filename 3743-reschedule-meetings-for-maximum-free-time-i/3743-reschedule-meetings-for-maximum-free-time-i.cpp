class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<vector<int>> meetings;
        int n = startTime.size();
        
        for (int i = 0; i < n; i++) {
            meetings.push_back({startTime[i], endTime[i]});
        }
        
        sort(meetings.begin(), meetings.end()); 
        
        vector<int> leftSpace;
        int l = 0;
        
        for (int i = 0; i < n; i++) {
            leftSpace.push_back(meetings[i][0] - l);
            l = meetings[i][1];
        }
        
        int maxFree = 0;
        int curr = 0;
        int r = 0;
        l = 0;
        
        while (r < k) {
            curr += leftSpace[r];
            r++;
        }
        
        int rightSpace = (r < n) ? (meetings[r][0] - meetings[r - 1][1]) : (eventTime - meetings[r - 1][1]);
        maxFree = max(maxFree, curr + rightSpace);
        
        for (; r < n; r++) {
            curr -= leftSpace[l];
            l++;
            curr += leftSpace[r];

            int rightSpace = (r < n - 1) ? leftSpace[r + 1] : (eventTime - meetings[r][1]);
            maxFree = max(maxFree, curr + rightSpace);
        }
        
        return maxFree;
    }
};
