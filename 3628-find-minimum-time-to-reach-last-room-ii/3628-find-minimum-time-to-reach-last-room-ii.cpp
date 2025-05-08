class Solution {
    int n,m;
    private:
      int solve (vector<vector<int>> &grid)
      {
        vector<vector<int>> vis (n,vector<int> (m,INT_MAX));
        priority_queue<pair<int,pair<int,pair<int,int>>> , vector<pair<int,pair<int,pair<int,int>>>> , greater<pair<int,pair<int,pair<int,int>>>>> pq;
        pq.push ({0,{0,{0,0}}});
        int x[]={0,+1,-1,0};
        int y[]={+1,0,0,-1};

        while (!pq.empty())
        {
            auto it=pq.top();
            int time=it.first;
            int cnt=it.second.first;
            int i=it.second.second.first;
            int j=it.second.second.second;
            pq.pop();  
            if (i==n-1 && j==m-1) return time;
          
            for (int k=0;k<4;k++)
            {
                int newI = i + x[k];
                int newJ = j + y[k];

                if (newI >=0 && newI<n && newJ >=0 && newJ<m)
                {
                    int currTime = max(grid[newI][newJ] - time , 0);
                    int newTime = currTime + time;
                    if (cnt==0) 
                    {
                        newTime+=1;
                    }
                    else 
                    {
                        newTime+=2;
                    }
                    if (newTime < vis[newI][newJ])
                    {
                        pq.push ({newTime,{cnt==1?0:cnt+1,{newI,newJ}}});
                        vis[newI][newJ]=newTime;
                    }
                }
            }
        }

        return -1;
      }
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        n=moveTime.size();
        m=moveTime[0].size();
        return solve (moveTime);
    }
};