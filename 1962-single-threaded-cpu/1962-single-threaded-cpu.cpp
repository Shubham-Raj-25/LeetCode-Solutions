class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++)
            tasks[i].push_back(i);
        
        sort(tasks.begin(),tasks.end());

        vector<int> ans;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        long long time = 0, idx = 0;

        while(idx<tasks.size() || !pq.empty()){
            if(pq.empty())
                time = max(time,(long long)tasks[idx][0]);
            
            while(idx<tasks.size() && time >= tasks[idx][0]){
                pq.push({tasks[idx][1],tasks[idx][2]});
                idx++;
            }

            auto top = pq.top();
            pq.pop();

            ans.push_back(top.second);
            time += (long long)top.first;

        }

        return ans;

    }
};