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
            // time.push_back(24*60 - data);
        }
        
        sort(time.begin(),time.end());

        for(int i=0;i<time.size();i++)
            for(int j=1;j<time.size();j++)
                if(i != j)
                    ans = min(ans, min(abs(time[i] - time[j]), 24*60 - abs(time[i] - time[j])));
        
        return ans;
    }
};