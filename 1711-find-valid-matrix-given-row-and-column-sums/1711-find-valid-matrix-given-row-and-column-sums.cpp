class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        // will greedy work?
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> ans(m,vector<int>(n));
        // vector<vector<int>> RunningRowSum(m,vector<int>(n));
        // vector<vector<int>> RunningColSum(m,vector<int>(n));

        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                // greedily put maximum val
                // no need to have running sum just subtract from the given arrays
                int val = min(rowSum[i],colSum[j]);
                // if(j!=0)
                //     val = min(val,rowSum[i]-RunningRowSum[i][j-1]);
                // if(i!=0)
                //     val = min(val,colSum[j]-RunningColSum[i-1][j]);
                
                ans[i][j] = val;

                rowSum[i] -= val;
                colSum[j] -= val;
                
                // if(j!=0)
                //     RunningRowSum[i][j] = RunningRowSum[i][j-1] + val;
                // else
                //     RunningRowSum[i][j] = val;
                
                // if(i!=0)
                //     RunningColSum[i][j] = RunningColSum[i-1][j] + val;
                // else
                //     RunningColSum[i][j] = val;

            }
        }

        return ans;

    }
};