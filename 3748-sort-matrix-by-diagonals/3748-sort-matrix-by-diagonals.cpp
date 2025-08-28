class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    //   left diagonals
        int n = grid.size();
        if(n == 1){
            return grid;
        }
        int rmin = 0, cmin =0, rmax = n,cmax = n;
        
        for(int i=0;i<n;i++){
            vector<int> data;
            for(int r=rmin, c=cmin; r<rmax && c<cmax; r++,c++){
                data.push_back(grid[r][c]);
            }
            sort(data.rbegin(),data.rend());
            int k = 0;
            for(int r=rmin, c=cmin; r<rmax && c<cmax; r++,c++){
                grid[r][c] = data[k++];
            }
            rmin += 1;
            cmax -= 1;
        }
        
        // top right diagonals
        rmin = 0, cmin = 1, rmax = n-1,cmax = n;
        for(int i=0;i<n-1;i++){
            vector<int> data;
            for(int r=rmin, c=cmin; r<rmax && c<cmax; r++,c++){
                data.push_back(grid[r][c]);
            }
            sort(data.begin(),data.end());
            int k = 0;
            for(int r=rmin, c=cmin; r<rmax && c<cmax; r++,c++){
                grid[r][c] = data[k++];
            }
            cmin+=1;
            rmax-=1;
        }
        
        return grid;
    }
};

/*

n*n

The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in decreasing order.
The diagonals in the top-right triangle are sorted in increating order.
  0 1 2
0 * * *
1 * * *
2 * * *

(0,0) -> (2,2) (n-1,n-1)
(1,0) -> (2,1) (1,n-2)
(2,0) -> (2,0) (2,n-3)

*/ 