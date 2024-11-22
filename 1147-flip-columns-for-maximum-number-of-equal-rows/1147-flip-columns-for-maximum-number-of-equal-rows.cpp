class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // store 0s and 1s position and find the maximum intersection
        unordered_map<string,int> mp;
        int m = matrix.size() , n = matrix[0].size();
        int ans = 0;

        for(int i=0;i<m;i++){
            string one = "", two = "";
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 1)
                    one += j + '_';
                else
                    two += j + '_';
            }
            mp[one]++;
            mp[two]++;
        }

        for(auto it: mp){
            cout << it.first << " " << it.second << endl;
            ans = max(ans, it.second);}
        
        return ans;
    }
};