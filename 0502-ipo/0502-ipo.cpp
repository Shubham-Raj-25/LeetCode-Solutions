class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> data;
        
        for(int i=0;i<profits.size();i++)
            data.push_back({capital[i],profits[i]});
        
        sort(data.begin(),data.end());

        priority_queue<int> pq;
        
        int idx = 0;

        while(k--){
            
            while(idx < data.size() && data[idx].first <= w){
                pq.push(data[idx].second);
                idx++;
            }

            if(pq.empty())
                break;
            
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};