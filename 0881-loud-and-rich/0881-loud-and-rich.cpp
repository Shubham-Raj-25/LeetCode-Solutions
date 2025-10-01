class Solution {
public:
    pair<int,int> dfs(int curr, vector<pair<int,int>>& data, vector<vector<int>>& adj,vector<int>& quiet){
        if(data[curr].first != -1){
            return data[curr];
        }
        int minQuiet = quiet[curr];
        int currAns = curr;
        for(int nei : adj[curr]){
            auto output = dfs(nei,data,adj,quiet);
            if(output.first < minQuiet){
                minQuiet = output.first;
                currAns = output.second;
            }
        }
        return data[curr] = {minQuiet,currAns};
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
    
        for (auto data : richer) {
            adj[data[1]].push_back(data[0]);
        }

        vector<pair<int,int>> data(n, {-1,-1});
        for (int i = 0; i < n; i++) {
            if(data[i].first == -1){
                dfs(i,data,adj,quiet);
            }
        }
        vector<int> ans;
        for(auto it : data){
            ans.push_back(it.second);
        }
        return ans;
    }
};

/*

richer[i] -> ai > bi


*/