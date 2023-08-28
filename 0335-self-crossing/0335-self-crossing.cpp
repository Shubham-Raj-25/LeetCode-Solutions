class Solution {
public:
    bool isSelfCrossing(vector<int>& dis) {
        
        for(int i = 3;i<dis.size();i++){
            // 4th line X 1st line -> 1>3 and 4>2 -> works for 5th line X 2nd line and so on...
            if(dis[i-3] >= dis[i-1] && dis[i] >= dis[i-2])
                return true;
            // 5th line X 1st line -> 2 = 4 and 1+5 = 3 -> works for 6th line X 2nd line and so on...
            else if(i<dis.size()-1 && dis[i-2] == dis[i] && dis[i-3] + dis[i+1] >= dis[i-1])
                return true;
            // 6 th line X 1st line ->
            else if(i<dis.size()-2 && dis[i-3]+dis[i+1] >= dis[i-1] && dis[i-2]+dis[i+2] >= dis[i] && dis[i] >= dis[i-2] && dis[i+1] <= dis[i-1])
                return true;
        }

        return false;

    }
};