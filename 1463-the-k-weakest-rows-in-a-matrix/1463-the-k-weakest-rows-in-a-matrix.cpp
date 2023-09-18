class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> data;
        for(int i=0;i<mat.size();i++){
            int ones = 0;
            while(ones<mat[0].size() && mat[i][ones]==1)
                ones++;
            data.push_back({ones,i});
        }

        sort(data.begin(),data.end());

        vector<int> ans;

        for(int i=0;i<min((int)mat.size(),k);i++)
            ans.push_back(data[i].second);
        
        return ans;
    }
};