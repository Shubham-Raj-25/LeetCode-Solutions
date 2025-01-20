class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int,int>> mapping(m*n+1);
        vector<int> colColoured(n,0), rowColoured(m,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mapping[mat[i][j]] = make_pair(i,j);
            }
        }

        for(int i=0;i<arr.size();i++){
            pair<int,int> points = mapping[arr[i]];
            rowColoured[points.first]++;
            colColoured[points.second]++;
            if(rowColoured[points.first] == n || colColoured[points.second] == m){
                return i;
            }
        }

        return -1;
    }   
};