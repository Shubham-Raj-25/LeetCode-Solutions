class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        set<vector<int>> st;
 
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            st.insert(it);
        }

        int ans = INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int rank = adj[i].size()+adj[j].size();
                if(st.find({i,j})!=st.end() || st.find({j,i})!=st.end())
                    rank -= 1;
                ans = max(ans,rank);
            }
        }
        
        return ans;
    }
};