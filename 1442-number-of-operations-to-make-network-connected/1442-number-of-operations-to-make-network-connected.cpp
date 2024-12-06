class Solution {
private:
    int findUPar(int u, vector<int>& par){
        if(par[u] == u)
            return u;
        return par[u] = findUPar(par[u],par);
    }

    void unionByRank(int u, int v, vector<int>& rank, vector<int>& par){
        int p_u = findUPar(u,par);
        int p_v = findUPar(v,par);

        if(p_u == p_v) return;

        if(rank[p_u] > rank[p_v])
            par[p_v] = p_u;
        else if(rank[p_v] > rank[p_u])
            par[p_u] = p_v;
        else{
            par[p_u] = p_v;
            rank[v]++;
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // find no of redundant PCs and disjointed PCs
        vector<int> par(n), rank(n,0);
        unordered_set<int> data;
        for(int i=0;i<n;i++) par[i] = i;    

        int redundant = 0, disjointedPcs = 0;

        for(auto connection : connections){
            int u = connection[0];
            int v = connection[1];
            if(findUPar(u,par) != findUPar(v,par))
                unionByRank(u,v,rank,par);
            else
                redundant++;
        }

        for(int i : par) data.insert(findUPar(i,par));

        disjointedPcs = data.size() - 1;
        
        if(disjointedPcs > redundant)
            return -1;
        
        return disjointedPcs;
    }
};