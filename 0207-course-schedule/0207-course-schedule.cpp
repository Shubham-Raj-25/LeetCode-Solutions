class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topo;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        queue<int> q;

        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        for(int i=0;i<numCourses;i++)
            if(indegree[i] == 0)
                q.push(i);

        while(q.size()){
            int curr = q.front();
            q.pop();
            topo.push_back(curr);

            for(int nei : adj[curr]){
                indegree[nei]--;
                if(indegree[nei] == 0)
                    q.push(nei);
            }
        }

        return topo.size() == numCourses;
    }
};