class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        vector<long long> data(n);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                data[j] += points[i][j];
            for(int j=1;j<n;j++)
                data[j] = max(data[j], data[j-1]-1);
            for(int j=n-2;j>=0;j--)
                data[j] = max(data[j], data[j+1]-1);
        }

        return *max_element(data.begin(),data.end());
    }
};