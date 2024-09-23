class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // indegree
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses),ans;
        queue<int> q;

        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        for(int i=0;i<numCourses;i++)
            if(indegree[i]==0)
                q.push(i);
        
        while(q.size()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for(int nei : adj[curr]){
                indegree[nei]--;
                if(indegree[nei] == 0)
                    q.push(nei);
            }
        }

        if(ans.size() == numCourses)
            return ans;
        return {};
    }
};