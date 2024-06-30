class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        
        for(int i=0;i<=n;i++)
            parent[i] = i;
    }
    
    int findUpar(int u){
        if(parent[u] == u)  return u;
        return parent[u] = findUpar(parent[u]);
    }

    void Union(int u, int v){
        int up_u = findUpar(u);
        int up_v = findUpar(v);

        if(up_u == up_v) return ;

        if(rank[up_u] > rank[up_v])
            parent[up_v] = up_u;
        else if(rank[up_v] > rank[up_u])
            parent[up_u] = up_v;
        else{
            parent[up_v] = up_u;
            rank[up_u]++;
        }
        return;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Solve the reverse question

        DSU alice = DSU(n);
        DSU bob = DSU(n);   
        int toKeep = 0;

        // begin by type3 edges
        for(int i=0;i<edges.size();i++){
            if(edges[i][0] == 3){
                int u = edges[i][1], v = edges[i][2];
                bool check = false;
                if(alice.findUpar(u) != alice.findUpar(v)){
                    alice.Union(u,v);
                    check = true;
                }
                if(bob.findUpar(u) != bob.findUpar(v)){
                    bob.Union(u,v);
                    check = true;
                }

                toKeep += check;
            }
        }

        // let's see Alice
        for(int i=0;i<edges.size();i++){
            if(edges[i][0] == 1){
                int u = edges[i][1], v = edges[i][2];
                if(alice.findUpar(u) != alice.findUpar(v)){
                    alice.Union(u,v);
                    toKeep++;
                }
            }
        }

        // let' see if alice can't travel to any node (means it has > 1 sets)
        for(int i=1;i<n;i++)
            if(alice.findUpar(i) != alice.findUpar(i+1))
                return -1;
        
        
        // Now ditto same for Bob

        for(int i=0;i<edges.size();i++){
            if(edges[i][0] == 2){
                int u = edges[i][1], v = edges[i][2];
                if(bob.findUpar(u) != bob.findUpar(v)){
                    bob.Union(u,v);
                    toKeep++;
                }
            }
        }

        // let' see if bob can't travel to any node (means it has > 1 sets)
        for(int i=1;i<n;i++)
            if(bob.findUpar(i) != bob.findUpar(i+1))
                return -1;
        
        return edges.size() - toKeep; // u will get toRemove
        
    }   
};