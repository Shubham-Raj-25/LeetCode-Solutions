class Solution {
public:
    pair<int,int> getDiameterAndFarthestNode(int curr, int par, vector<vector<int>>& adj){
        int ans = 0, farthestNode = curr;
        for(auto nei : adj[curr]){
            if(nei != par){
                auto data = getDiameterAndFarthestNode(nei,curr,adj);
                if(data.first + 1 > ans){
                    ans = data.first + 1;
                    farthestNode = data.second;
                }
            }
        }
        return {ans,farthestNode};
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // max(max(d2,d1), d1/2 + d2/2 + 1)
        int n = edges1.size() + 1, m = edges2.size()+1;
        vector<vector<int>> adj1(n), adj2(m);
        
        for(auto edge: edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        for(auto edge: edges2){
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        int dia1 = 0, dia2 = 0;

        int farthestNode1 = getDiameterAndFarthestNode(0,-1,adj1).second;
        dia1 = getDiameterAndFarthestNode(farthestNode1,-1,adj1).first;

        int farthestNode2 = getDiameterAndFarthestNode(0,-1,adj2).second;
        dia2 = getDiameterAndFarthestNode(farthestNode2,-1,adj2).first;

        return max((int)max(dia1,dia2),(int)ceil((double)dia1/2) + (int)ceil((double)dia2/2) + 1);
    }
};