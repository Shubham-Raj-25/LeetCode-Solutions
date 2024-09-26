class MyCalendar {
public:
    vector<pair<int,int>> data;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it: data)
            if(start < it.second && end > it.first)
                return false;
        data.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */