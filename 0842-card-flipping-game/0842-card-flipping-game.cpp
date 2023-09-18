class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        
        int ans = INT_MAX;

        for(int i=0;i<fronts.size();i++){
            int a = fronts[i];
            int b = backs[i];
            bool truea = true;
            bool trueb = true;
            for(int k=0;k<fronts.size();k++){
                if(fronts[k]==a && backs[k]==a)
                    truea = false;
                if(fronts[k]==b && backs[k]==b)
                    trueb = false;
            }
            
            if(truea)
                ans = min(ans,a);
            if(trueb)
                ans = min(ans,b);
        
        }

        return ans == INT_MAX ? 0 : ans ;
    }
};