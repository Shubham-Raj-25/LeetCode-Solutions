class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        unordered_map<int,vector<int>> stop2Bus;

        for(int i=0;i<routes.size();i++)
            for(int j:routes[i])
                stop2Bus[j].push_back(i);
        
        unordered_set<int> seen = {source};

        queue<pair<int,int>> q;

        q.push({source,0});

        while(!q.empty()){
            int stop = q.front().first;
            int buses= q.front().second;
            q.pop();

            if(stop == target)
                return buses;
            
            for(int i:stop2Bus[stop]){
                for(int j: routes[i]){
                    if(seen.find(j)==seen.end()){
                        seen.insert(j);
                        q.push({j,buses+1});
                    }
                }
                routes[i].clear();  // to optimize maybe
            }
        }
        return -1;
    }
};