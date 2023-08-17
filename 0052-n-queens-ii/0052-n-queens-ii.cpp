class Solution {
public:
    void solve(int col,vector<vector<string>>& ans,vector<string>& board,vector<int> leftRow,vector<int> upperD, vector<int> lowerD,int n)
    {
        // recusrive function

        // Base Case

        if(col == n)
        {
            ans.push_back(board);
            return;
        }

        for(int row =0; row < n; row++)
        {
            if(leftRow[row] ==0 && upperD[n-1+col-row] == 0 && lowerD[col+row] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = upperD[n-1+col-row]=lowerD[col+row] =1;
                
                //recursion call
                solve(col+1,ans,board,leftRow,upperD, lowerD,n);

                //backtracking
                board[row][col] = '.';
                leftRow[row] = upperD[n-1+col-row]=lowerD[col+row] =0;
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);

        string s(n,'.');

        for(int i=0; i<n; i++)
            board[i] = s;

        vector<int> leftRow(n,0), upperD(2*n-1,0), lowerD(2*n-1,0);

        solve(0,ans,board,leftRow,upperD,lowerD,n);

        return ans.size();
    }
};