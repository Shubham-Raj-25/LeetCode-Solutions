class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),comp);
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<events.size();i++)
            pq.push({events[i][2],i});
        
        int ans = 0;

        for(int i=0;i<events.size();i++){
            while(pq.size() && events[pq.top().second][0] <= events[i][1])
                pq.pop();
            int to_add = 0;
            if(pq.size())
                to_add = pq.top().first;
            ans = max(ans, events[i][2] + to_add);
        }

        return ans;
    }
};