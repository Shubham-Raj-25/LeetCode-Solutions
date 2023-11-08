class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(fx-sx);
        int y = abs(fy-sy);
        if(max(x,y) > t or (max(x,y)==0 and (t>0 and t<2)))
            return false;
        
        return true;
    }
};