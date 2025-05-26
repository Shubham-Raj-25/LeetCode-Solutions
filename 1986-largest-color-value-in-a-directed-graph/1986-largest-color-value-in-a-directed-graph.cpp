// A bit of DP is involved in calculating the max freq of color till the current node
// as we need a valid path, we will traverse throught all valid paths using topo sort // Kahn's algo
// This solution is not mine but replicated from somewhere

class Solution {
public:
    int largestPathValue(string color, vector<vector<int>>& edges) {
        
        int n = color.size(); // no of nodes

        map<int,vector<int>> graph;

        vector<int> indegree(n,0);

        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }

        queue<int> q;

        for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);

        vector<vector<int>> colorCnt(n,vector<int>(26,0)); // this is the dp thing i guess, we keep track of the max frequency of colors achieve till each node

        int ans = INT_MIN;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            colorCnt[node][color[node]-'a']++; // incrementing the color count of the element at node

            for(int i=0;i<26;i++) ans = max(ans,colorCnt[node][i]); // storing the max frequency in ans of that node

            for(auto itr:graph[node]){
                
                indegree[itr]--;
                if(indegree[itr]==0) q.push(itr);
                
                for(int i=0;i<26;i++) // updating the colorCnt for node's children as it comes after that
                     colorCnt[itr][i] = max(colorCnt[itr][i],colorCnt[node][i]); 
            }
        }

        for(int i=0;i<n;i++) if(indegree[i]!=0) return -1; // detection of cycle

        return ans;

    }
};