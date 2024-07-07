class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        int n = recipes.size();
        map<string,vector<string>> adj;
        map<string,int> indegree;

        unordered_set<string> supply;
        for(auto it: supplies) supply.insert(it);

        for(int i=0;i<n;i++){
            int idg = 0;
            
            for(int j=0;j<ingredients[i].size();j++){
                adj[ingredients[i][j]].push_back(recipes[i]);
                if(!supply.count(ingredients[i][j]))
                    idg++;
            }

            indegree[recipes[i]] = idg;
        }

        queue<string> q;

        for(auto it: indegree)
            if(!it.second)
                q.push(it.first);
        
        while(q.size()){
            string s = q.front();
            q.pop();

            for(auto e : adj[s]){
                indegree[e]--;
                if(indegree[e] <= 0)
                    q.push(e);
            }
        }

        for(auto it: indegree)
            if(it.second < 1)
                ans.push_back(it.first);

        return ans;

    }
};

/*

    a -> x, b
    b -> y, c  
    c -> m, n
    y -> a, c

    [x,y,m,n] + c + b + a + y

    TC : O(n^n) = 100^100 (TLE)

    pq ?

    jaise hi ek bana, pehle vaale ko inform karo
    
    try to create a graph

*/