class Solution {
public:
    bool dfs(int currNode, int time, vector<int>& visTime, vector<vector<int>>& adj){
        if(currNode == 0){
            visTime[0] = time;
            return true;
        }
        
        visTime[currNode] = time;
        for(auto nei : adj[currNode]){
            if(visTime[nei] == INT_MAX && dfs(nei,time+1,visTime,adj)){
                return true;
            }
        }
        visTime[currNode] = INT_MAX;
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size()+1;
        vector<int> degree(n,0);
        vector<vector<int>> adj(n);
        queue<pair<int,int>> q;
        vector<bool> visAlice(n,false);
        int ans = INT_MIN;
        
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }        

        vector<int> bobVisTime(n,INT_MAX);
        dfs(bob,0,bobVisTime,adj);

        // for(auto it: bobVisTime){
        //     cout << it << " ";
        // }

        int time = 0;
        q.push({0,0});
        
        while(q.size()){
            int k = q.size();
            while(k--){
                int currNode = q.front().first;
                int currCost = q.front().second;
                q.pop();
                
                visAlice[currNode] = true;
                
                if(time < bobVisTime[currNode])
                    currCost += amount[currNode];
                else if(time == bobVisTime[currNode])
                    currCost += amount[currNode]/2;

                if(degree[currNode] == 1 && currNode != 0){ // leaf node
                    ans = max(currCost,ans);
                    continue;
                }
                
                for(int nei : adj[currNode]){
                    if(!visAlice[nei]){
                        q.push({nei,currCost});
                    }
                }
            }
            time++;
        }

        return ans;
    }   
};

/*

// assuming bob will travel the shortest path

0 : n-1

      *   
         * 
  *    *   *
         *   *


    n-1
        alice visited
        bob visited
    increasing number 
    decreasing number ? 

    bob will have a fixed path -> in a tree from a node there's only a single
                                  path to reach the root
    How to know bob's path? dfs?

    trace bob's path with time via backtracking
    then do a bfs for alice ? 
*/ 