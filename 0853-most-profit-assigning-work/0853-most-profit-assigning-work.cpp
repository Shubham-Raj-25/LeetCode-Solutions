class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> data;
        int profitMade = 0;
        
        for(int i=0;i<profit.size();i++)
            data.push_back({profit[i],difficulty[i]});
        
        sort(data.rbegin(),data.rend());
        sort(worker.rbegin(),worker.rend());

        int i = 0;
        for(int j=0;j<worker.size();j++){
            while(i < data.size() && worker[j] < data[i].second)
                i++;
            if(i == data.size())
                break;
            if(worker[j] >= data[i].second)
                profitMade += data[i].first;
        }

        return profitMade;
    }
};