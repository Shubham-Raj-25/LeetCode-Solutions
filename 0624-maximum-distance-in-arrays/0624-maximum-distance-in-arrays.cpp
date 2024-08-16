class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        sort(arrays.begin(),arrays.end());
        int opt1 , opt2;
        int mini = arrays[0][0];
        int maxi = INT_MIN;
        
        for(int i=1;i<arrays.size();i++)
            maxi = max(maxi,arrays[i].back());
        
        opt1 = maxi-mini;

        maxi = arrays[0].back();
        mini = INT_MAX;

        for(int i=1;i<arrays.size();i++)
            mini = min(mini, arrays[i][0]);

        opt2 = maxi - mini;

        return max(opt1,opt2);
    }
};