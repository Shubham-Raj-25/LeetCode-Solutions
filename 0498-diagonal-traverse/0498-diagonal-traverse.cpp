class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans(m*n);
        int idx = 0;

        int i = 0;
        int j = 0;

        ans[idx++] = mat[i][j];

        bool up = true;

        while(idx!=ans.size()){
            if(up){
                j++;

                while(j!=0 && i!=m-1){
                    if(j<n)
                        ans[idx++] = mat[i][j];
                    i++;
                    j--;
                }

                ans[idx++] = mat[i][j];
                up = false;
            }
            else{
                i++;

                while(i!=0 && j!=n-1){
                    if(i<m)
                        ans[idx++] = mat[i][j];
                    i--;
                    j++;
                }

                ans[idx++] = mat[i][j];
                up = true;
            }
        }
        return ans;
    }
};