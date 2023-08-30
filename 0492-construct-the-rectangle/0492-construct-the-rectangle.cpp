class Solution {
public:
    vector<int> constructRectangle(int area) {
        int ans = area;
        int diff = INT_MAX;

        for(int i=1;i<=area;i++){
            if(area%i==0){
                if(abs(i-(area/i)) < diff){
                    diff = abs(i-(area/i));
                    ans = i;
                }
            }
        }

        vector<int> res;

        if(ans > area/2)
            res = {ans,area/ans};
        else
            res = {area/ans,ans};
        
        return res;
    }
};