class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        vector<pair<int,int>> projects;

        for(int i=0;i<profits.size();i++)
            projects.push_back({capital[i],profits[i]});

        priority_queue<int> pq;

        sort(projects.begin(),projects.end());

        int i = 0; 
        int ans = w;

        while(k--){
            while(i<projects.size() && projects[i].first <= ans){
                pq.push(projects[i].second);
                i++;
            }

            if(pq.empty()) break;

            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};