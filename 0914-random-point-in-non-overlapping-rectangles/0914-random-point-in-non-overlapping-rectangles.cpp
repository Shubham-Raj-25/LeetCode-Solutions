class Solution {
public:
    vector<vector<int>> data;
    vector<int> area;
    Solution(vector<vector<int>>& rects) {
        data = rects;
        for(auto r:rects)
            area.push_back((r[2]-r[0]+1)*(r[3]-r[1]+1)+ (area.empty() ? 0 : area.back()));
    }   
    
    vector<int> pick() {
        int rnd = rand() % area.back();
        int rect = upper_bound(area.begin(), area.end(), rnd)-area.begin();
        

        int x = data[rect][0]+rand()%(data[rect][2]-data[rect][0]+1);
        int y = data[rect][1]+rand()%(data[rect][3]-data[rect][1]+1);

        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */