class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();
        map<int,vector<pair<int,int>>,greater<int>> mp; // descending order of key
        vector<int> maxRow(r) , maxCol(c); // max path encountered in the row / col so far
        int ans = 0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                mp[mat[i][j]].push_back({i,j});
            }
        }

        for(auto it: mp){
            int val = it.first;
            vector<pair<int,int>> cells = it.second;
            int duplicates = cells.size();
            vector<int> data(duplicates);
            for(int i=0;i<duplicates;i++){
                int currR = it.second[i].first, currC = it.second[i].second;
                data[i] = max(maxCol[currC], maxRow[currR]) + 1; 
                ans = max(ans, data[i]);
            }
            
            for(int i=0;i<duplicates;i++){
                int currR = it.second[i].first, currC = it.second[i].second;
                maxRow[currR] = max(data[i], maxRow[currR]);
                maxCol[currC] = max(data[i], maxCol[currC]);
            }
        }

        return ans;
    }
};