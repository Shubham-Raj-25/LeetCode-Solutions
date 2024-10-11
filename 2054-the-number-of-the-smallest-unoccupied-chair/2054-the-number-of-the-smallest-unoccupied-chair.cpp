class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> booked;
        priority_queue<int,vector<int>,greater<int>> available;
        
        for(int i=0;i<times.size();i++){
            times[i].push_back(i);
            available.push(i);
        }

        sort(times.begin(),times.end());

        for(int i=0;i<times.size();i++){
            int frnd = times[i][2];
            int s_time = times[i][0];
            int e_time = times[i][1];

            while(booked.size() && booked.top().first <= s_time){
                available.push(booked.top().second);
                booked.pop();
            }

            if(frnd == targetFriend)
                return available.top();

            booked.push({e_time,available.top()});
            available.pop();
        }

        return -1;
    }
};