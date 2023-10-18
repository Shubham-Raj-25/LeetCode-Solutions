class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int ans=0;
        vector<int>t(n+1,0),indeg(n+1,0);
        for(int i=0;i<n;i++) t[i+1]=time[i];
        vector<vector<int>>g(n+1);
        for(auto i:relations){ 
            g[i[0]].push_back(i[1]);
            indeg[i[1]]++;
        }
        queue<int>q;
        for(int i=1;i<=n;i++) if(indeg[i]==0) q.push(i);
        while(!q.empty()){
            int node=q.front(); q.pop();
            ans=max(ans,t[node]);
            for(auto i:g[node]){
                t[i]=max(t[i],t[node]+time[i-1]);
                indeg[i]--;
                if(indeg[i]==0) q.push(i);
            }
        }
        return ans;
    }
};