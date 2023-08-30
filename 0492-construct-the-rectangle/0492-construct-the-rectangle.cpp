class Solution {
public:
    vector<int> constructRectangle(int area) {
        for(int i=sqrt(area);i>=1;i--)
            if(!(area%i))
                return {area/i,i};
        
        return {0,0};
    }
};