class Solution {
public:
    map<pair<int,int>,double> cache;

    double func(int poured, int row, int glass){

        if(row<0 || glass <0 || glass>row)
            return 0.0;
        
        if(row==0 && glass==0) return poured;
         
        if(cache.find({row,glass})!=cache.end())
            return cache[{row,glass}];

        double left = max(0.0,func(poured,row-1,glass-1)-1);

        double right = max(0.0,func(poured,row-1,glass)-1);

        return cache[{row,glass}] = (left+right)/2;

    }

    double champagneTower(int poured, int row, int glass) {
        return min(1.0,func(poured,row,glass));
    }
};