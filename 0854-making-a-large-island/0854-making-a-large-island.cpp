class DisjointSet {
public:
    vector<int> rank, parent, size; 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        DisjointSet ds(n*n);

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                
            if(grid[row][col] == 0)
                continue;
            
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};

            for(int i=0;i<4;i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]){
                    
                    int node = row*n+col;
                    int adjNode = nrow*n+ncol;
                    
                    ds.unionBySize(node,adjNode);
                }
            }
            }
        }


        int maxi = 0;

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                
            if(grid[row][col]==1)
                    continue;
                
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};
            set<int> components;

            for(int i=0;i<4;i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==1)
                    components.insert(ds.findUPar(nrow*n+ncol));                        
            }

            int sizeTotal = 0;
            for(auto it:components){
                sizeTotal+= ds.size[it];
            }

            maxi = max(maxi,sizeTotal+1);
            }
        }

        for(int i=0;i<n*n;i++)  maxi = max(maxi,ds.size[ds.findUPar(i)]);
        
        return maxi;
    }
};