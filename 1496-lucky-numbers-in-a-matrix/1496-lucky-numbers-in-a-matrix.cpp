class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_set<int> min_row, max_col;
        
        for(int i=0;i<matrix.size();i++){
            int mini = INT_MAX;
            for(int j=0;j<matrix[0].size();j++)
                mini = min(matrix[i][j],mini);
            min_row.insert(mini);
        }
        for(int j=0;j<matrix[0].size();j++){
            int maxi = INT_MIN;
            for(int i=0;i<matrix.size();i++)
                maxi = max(matrix[i][j],maxi);
            max_col.insert(maxi);
        }
        
        vector<int> ans;

        for(auto it: max_col)
            if(min_row.count(it))
                ans.push_back(it);

        return ans;
    }
};