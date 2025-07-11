class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<n;i++) pq.push({meetings[0][0],i});
        
        int count[101] = {0};

        for(auto it: meetings){
            int start = it[0];
            int end = it[1];
            while(pq.top().first < start){
                pq.push({start,pq.top().second});
                pq.pop();
            }
            int room = pq.top().second;
            long long time = pq.top().first;
            pq.pop();
            count[room]++;
            time += end-start;
            pq.push({time,room});
        }
        
        return max_element(begin(count), end(count)) - begin(count);;
    }
};