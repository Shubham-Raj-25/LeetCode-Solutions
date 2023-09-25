class Solution {
public:
    int helper(string report,unordered_set<string>& pos, unordered_set<string>& neg){
        int ans = 0;

        for(int j=0;j<report.size();j++){
            string temp;
            while(j<report.size() && report[j]!=' ')
                temp.push_back(report[j++]);
            if(pos.find(temp)!=pos.end())
                ans+=3;
            else if(neg.find(temp)!=neg.end())
                ans--;
        }

        return ans;
    }

    static bool compare(std::pair<int, long long>& a, std::pair<int, long long>& b) {
    if (a.first != b.first) {
        return a.first > b.first;
    } else {
        return a.second < b.second;
    }
}

    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> pos, neg;
        for(auto it:positive_feedback) pos.insert(it);
        for(auto it:negative_feedback) neg.insert(it);

        vector<pair<int,long long>> data;
        
        for(int i=0;i<report.size();i++){
            int score = helper(report[i],pos,neg);
            data.push_back({score,student_id[i]});
        }

        sort(data.begin(),data.end(), compare);

        vector<int> ans;

        for(int i=0;i<k;i++)
            ans.push_back(data[i].second);

        return ans;
    }
};