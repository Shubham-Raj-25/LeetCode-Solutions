class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        
        vector<int> temp;
        if(m*n != original.size())
            return ans;
        
        for(int i=0;i<original.size();i++){
            if(temp.size() && i % n == 0){
                ans.push_back(temp);
                temp.clear();
            }
            temp.push_back(original[i]);
        }
        ans.push_back(temp);
        return ans;
    }
};