class TopVotedCandidate {
public:
    vector<int> data;
    vector<int> times;
    TopVotedCandidate(vector<int>& persons, vector<int>& time) {
        unordered_map<int,int> mp;
        int max_count = 0;
        times = time;
        int winner = -1;
        for(int i=0;i<persons.size();i++){
            mp[persons[i]]++;
            if(mp[persons[i]] >= max_count){
                max_count = mp[persons[i]];
                winner = persons[i];
            }
            data.push_back(winner);
        }
    }
    
    int q(int t) {
        int idx = lower_bound(times.begin(),times.end(),t) - times.begin();

        while(idx == times.size() || times[idx] > t)
            idx--;

        return data[idx];
    }
};