
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        vector<int> sums;
        int n = weights.size();

        if(n==k || k==1) return 0;

        for(int i=0;i<n-1;i++)
            sums.push_back(weights[i]+weights[i+1]);
        
        sort(sums.begin(),sums.end());

        long long maxi,mini;
        maxi = mini = 0;

        for(int i=0;i<k-1;i++){
            maxi += sums[n-2-i]; // this will pick up the last/max k value
            mini += sums[i]; // this will up smallest k values
        }

        return maxi-mini;

    }
};