class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int i=0,j=0;
        int n1=players.size(),n2=trainers.size();
        int res=0;

        while(i<n1 && j<n2)
        {
            if(players[i]>trainers[j])
                j++;
            else if(players[i]<=trainers[j])
            {
                i++;j++;
                res++;
            }
        }

        return res;
        
    }
};