class Solution {
public:
    int mod = 1e9+7;
    map<vector<int>,int> mp;
    int func(int i, int j, int max,int m, int n){
        if(i<0 || j<0 || i==m || j==n)
            return 1;
        if(max<=0)
            return 0;
        
        if(mp.find({i,j,max})!=mp.end())
            return mp[{i,j,max}];
        
        int ans = 0;
        
        int di[4] = {1,0,-1,0};
        int dj[4] = {0,-1,0,1};

        for(int k=0;k<4;k++){
            int ni = i+di[k];
            int nj = j+dj[k];

            ans = ans%mod+func(ni,nj,max-1,m,n)%mod;
        }

        return mp[{i,j,max}] = ans%mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        return func(startRow,startColumn,maxMove,m,n);
    }
};