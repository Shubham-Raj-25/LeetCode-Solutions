class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // convert every timestamp to minute past 00:00 (handle both cw and acw cases)
        vector<int> time;
        int ans = INT_MAX;

        for(string t : timePoints){
            int hour = stoi(t.substr(0,2));
            int minutes = stoi(t.substr(3,2));
            int data = hour * 60 + minutes;
            time.push_back(data);
        }
        
        sort(time.begin(),time.end());

        for(int i=1;i<time.size();i++)
                ans = min(ans, min(abs(time[i] - time[i-1]), 24*60 - abs(time[i] - time[i-1])));
        
        ans = min(ans, min(abs(time[0] - time.back()), 24*60 - abs(time[0] - time.back())));

        return ans;
    }
};