class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        for(int i=0;i<grumpy.size();i++)
            ans += grumpy[i] == 0 ? customers[i] : 0;
        
        // sliding window to get the maximum extra addition
        int extra_addition = 0;

        for(int i=0;i<minutes;i++)
            extra_addition += grumpy[i] == 1 ? customers[i] : 0;
        
        int l = 0, r = minutes-1;
        
        int maxi = extra_addition;

        while(r < grumpy.size()-1){
            if(grumpy[l] == 1)
                extra_addition -= customers[l];
            l++;
            r++;
            if(grumpy[r] == 1)
                extra_addition += customers[r];
            maxi = max(maxi, extra_addition);
        }
        return ans + maxi;
    }
};