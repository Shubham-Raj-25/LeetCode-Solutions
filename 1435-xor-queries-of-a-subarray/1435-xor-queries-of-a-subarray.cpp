class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = queries.size();
        int m = arr.size();
        for(int i=0;i<n;i++){
            int left = queries[i][0];
            int right = queries[i][1];
            int xr=0;
            for(int i=0;i<m;i++){
                while(left<=right){
                    xr^=arr[left];
                    left++;
                }
            }
            ans.push_back(xr);
        }
        return ans;
    }
};