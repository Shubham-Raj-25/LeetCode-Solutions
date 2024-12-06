class Solution {
private:
    int findUPar(int u, vector<int>& par){
        if(par[u] == u) return u;
        return par[u] = findUPar(par[u],par);
    }
    void unionByRank(int u, int v, vector<int>& par, vector<int>& rank){
        int uPar_u = findUPar(u,par);
        int uPar_v = findUPar(v,par);

        if(uPar_u == uPar_v) return;
        if(rank[uPar_u] > rank[uPar_v])
            par[uPar_v] = uPar_u;
        else if(rank[uPar_v] > rank[uPar_u])
            par[uPar_u] = uPar_v;
        else{
            par[uPar_u] = uPar_v;
            rank[uPar_v]++;
        }
    }

public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> rank(n,0),par(n);
        int ans = 0;

        for(int i=0;i<n;i++) par[i] = i;

        for(int i=0;i<n;i+=2)
            unionByRank(row[i],row[i+1],par,rank);
        
        for(int i=0;i<n;i+=2){
            int u = findUPar(i,par);
            int v = findUPar(i+1,par);
            if(u!=v){
                unionByRank(u,v,par,rank);
                ans++;
            }
        }

        return ans;
    }   
};