class RecentCounter {
public:
    vector<int> data;
    RecentCounter() {
        
    }
    
    int ping(int t) {   
        data.push_back(t);
        int idx = lower_bound(data.begin(),data.end(),t-3000)-data.begin();
        return data.size()-idx;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */