class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> ballToColor;
        vector<int> ans;
        unordered_map<int,int> colorFreq;
        unordered_set<int> currentColors;

        for(auto query : queries){
            int ball = query[0];
            int color = query[1];

            // if the ball is already colored
            if(ballToColor[ball] != 0){
                int prevColor = ballToColor[ball];
                colorFreq[prevColor]--;
                if(colorFreq[prevColor] == 0){
                    currentColors.erase(prevColor);
                }
            }
            
            ballToColor[ball] = color;
            colorFreq[color]++;
            currentColors.insert(color);

            ans.push_back(currentColors.size());
        }

        return ans;
    }
};

/*

limit+1 balls
[0,limit]
x,y -> mark ball x with y

After each query,
you need to find the number of distinct colors among the balls.

mp[ball->color] -> vector will do
mp[color->freq] -> unoredered map
set[colors] -> unordered Set
*/ 