class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // indegree calculation ? 
        vector<int> indegree(n,0);
        for(auto edge : edges)
            indegree[edge[1]]++;
        int ans = -1;

        for(int i=0;i<n;i++)
            if(indegree[i] == 0)
                if(ans == -1)
                    ans = i;
                else
                    return -1;
        
        return ans;
    }
};