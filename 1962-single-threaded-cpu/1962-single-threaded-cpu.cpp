class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> order;
        
        for(int i=0;i<tasks.size();i++)
            tasks[i].push_back(i);

        sort(tasks.begin(),tasks.end());

        long long curr_time = tasks[0][0];
        int idx = 0;

        while(idx < tasks.size() && tasks[idx][0] <= curr_time){
            pq.push({tasks[idx][1],tasks[idx][2]});
            idx++;
        }

        while(pq.size()){
            auto curr = pq.top();
            pq.pop();
            order.push_back(curr.second);
            curr_time += curr.first;
            
            if(pq.empty()){
                if(idx < tasks.size() && (long long) tasks[idx][0] > curr_time)
                    curr_time = tasks[idx][0];
            }
            
            while(idx < tasks.size() && tasks[idx][0] <= curr_time){
                pq.push({tasks[idx][1],tasks[idx][2]});
                idx++;
            }
        }

        return order;

    }
};