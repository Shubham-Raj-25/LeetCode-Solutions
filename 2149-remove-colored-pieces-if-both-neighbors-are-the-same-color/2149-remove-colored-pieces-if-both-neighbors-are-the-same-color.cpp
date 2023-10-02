class Solution {
public:
    bool winnerOfGame(string colors) {
     int countAAA = 0, countBBB = 0;
     if(colors.size()<3)
        return false;
     for(int i=0;i<colors.size()-2;i++){
         if(colors[i]=='A' && colors[i+1]=='A' && colors[i+2]=='A')
            countAAA++;
        else if(colors[i]=='B' && colors[i+1]=='B' && colors[i+2]=='B')
            countBBB++;
     }   
     return countAAA > countBBB;
    }
};