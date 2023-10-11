class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {

        vector<int> start;
        vector<int> end;
        vector<int> ans;

        for(auto it:flowers){
            start.push_back(it[0]);
            end.push_back(it[1]);
        }

        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        for(int time:persons){
            // below calculates the no of flowers with ending time< time
            int ending =  lower_bound(end.begin(),end.end(),time)-end.begin();
            //below calculates the no of flowers with starting time < time
            int starting= upper_bound(start.begin(),start.end(),time)-start.begin();
            ans.push_back(starting-ending);
        }

        return ans;
    }
};